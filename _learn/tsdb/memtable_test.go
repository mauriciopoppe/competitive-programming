package main

import (
	"reflect"
	"testing"
)

func TestMemtable(t *testing.T) {
	memtable := NewMemtable()

	// Write some entries
	memtable.Write(map[string]string{"hello": "world", "a": "a"}, 100)
	memtable.Write(map[string]string{"hello": "world", "b": "b"}, 200)
	memtable.Write(map[string]string{"hello": "world", "c": "c"}, 300)
	memtable.Write(map[string]string{"hello": "world", "a": "a", "b": "b"}, 400)

	// Read the entries
	result := memtable.Read(map[string]string{"hello": "world", "a": "a"})
	expected := []any{100, 400}
	if !reflect.DeepEqual(result, expected) {
		t.Errorf("Read() returned %+v, expected %+v", result, expected)
	}

	result = memtable.Read(map[string]string{"hello": "world"})
	expected = []any{100, 200, 300, 400}
	if !reflect.DeepEqual(result, expected) {
		t.Errorf("Read() returned %+v, expected %+v", result, expected)
	}

	result = memtable.Read(map[string]string{"hello": "world", "i dont exist": ":("})
	expected = []any{}
	if !reflect.DeepEqual(result, expected) {
		t.Errorf("Read() returned %+v, expected %+v", result, expected)
	}
}
