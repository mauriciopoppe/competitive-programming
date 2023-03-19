// go run main.go

package main

import (
	"fmt"
	"time"
)

type Entry struct {
	// id is the entry id, in the impl it's an id that increases e.g. a time
	id time.Time
	// labels are the labels that identify the entry.
	labels map[string]string
	// value is the entry value.
	value any

	// next is an iterator to the next Entry.
	next *Entry
}

type Memtable struct {
	// are the entries in the DB, append only and immutable.
	head *Entry
	tail *Entry

	// index is a reverse index of a label to an entry.
	index map[string][]*Entry
}

func NewMemtable() *Memtable {
	dummy := &Entry{}
	return &Memtable{
		head:  dummy,
		tail:  dummy,
		index: make(map[string][]*Entry),
	}
}

// intersect intersects two arrays of Entries based on their id.
func intersect(a []*Entry, b []*Entry) []*Entry {
	out := make([]*Entry, 0)
	i := 0
	j := 0
	for i < len(a) && j < len(b) {
		if a[i].id.Equal(b[j].id) {
			out = append(out, a[i])
			i += 1
			j += 1
		} else if a[i].id.Before(b[j].id) {
			i += 1
		} else {
			j += 1
		}
	}
	return out
}

func (m *Memtable) encode(k, v string) string {
	return fmt.Sprintf("%s::%s", k, v)
}

func (m *Memtable) Read(labels map[string]string) []any {
	// read temporary results for every label
	tempResults := make([][]*Entry, 0)
	for k, v := range labels {
		key := m.encode(k, v)
		tempResults = append(tempResults, m.index[key])
	}

	// intersect
	if len(tempResults) == 0 {
		return make([]any, 0)
	}
	intersection := tempResults[0]
	for i := 1; i < len(tempResults); i += 1 {
		intersection = intersect(intersection, tempResults[i])
	}

	out := make([]any, 0)
	for _, e := range intersection {
		out = append(out, e.value)
	}
	return out
}

func (m *Memtable) Write(labels map[string]string, value any) {
	e := &Entry{
		id:     time.Now(),
		labels: labels,
		value:  value,
	}

	// process entry
	for k, v := range labels {
		key := m.encode(k, v)
		m.index[key] = append(m.index[key], e)
	}
	m.tail.next = e
	m.tail = m.tail.next
}
