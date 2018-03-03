package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func count(words []string) int {
	m := make(map[string]bool)
	for _, v := range words {
		if m[v] {
			return 0
		}
		m[v] = true
	}
	return 1
}

// Ins .
type Ins struct {
	r   string
	op  string
	q   int
	cl  string
	cop string
	cr  int
}

// Pass .
func (i Ins) Pass(reg map[string]int) bool {
	left := reg[i.cl]
	right := i.cr
	switch i.cop {
	case ">":
		return left > right
	case "<":
		return left < right
	case ">=":
		return left >= right
	case "<=":
		return left <= right
	case "!=":
		return left != right
	case "==":
		return left == right
	}
	return false
}

// Exec .
func (i Ins) Exec(reg map[string]int) int {
	switch i.op {
	case "inc":
		reg[i.r] += i.q
	case "dec":
		reg[i.r] -= i.q
	}
	return reg[i.r]
}

// ParseOne .
func ParseOne(r io.Reader) []Ins {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanLines)
	ins := make([]Ins, 0)
	for scanner.Scan() {
		line := scanner.Text()
		st := Ins{}
		var iff string
		fmt.Sscanf(line, "%s %s %d %s %s %s %d", &st.r, &st.op, &st.q, &iff, &st.cl, &st.cop, &st.cr)
		ins = append(ins, st)
	}
	return ins
}

// One .
func One(ins []Ins) int {
	reg := make(map[string]int)
	for _, i := range ins {
		if i.Pass(reg) {
			i.Exec(reg)
		}
	}
	mx := 0
	for _, v := range reg {
		if v > mx {
			mx = v
		}
	}
	return mx
}

// Two .
func Two(ins []Ins) int {
	reg := make(map[string]int)
	mx := 0
	for _, i := range ins {
		if i.Pass(reg) {
			newValue := i.Exec(reg)
			if newValue > mx {
				mx = newValue
			}
		}
	}
	return mx
}

func main() {
	f, _ := os.Open("./in")
	ins := ParseOne(f)
	fmt.Println(One(ins))
	fmt.Println(Two(ins))
}
