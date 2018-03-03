package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

// ParseOne .
func ParseOne(r io.Reader) string {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanLines)
	scanner.Scan()
	return scanner.Text()
}

const (
	good   = iota
	ignore = iota
)

// One .
func One(in string) int {
	total := 0
	stack := 0
	i := 0
	state := good
	for i < len(in) {
		if in[i] == '<' {
			state = ignore
			i++
			continue
		}
		if in[i] == '{' {
			if state != ignore {
				stack++
				total += stack
			}
			i++
			continue
		}
		if in[i] == '!' {
			i += 2
			continue
		}
		if in[i] == '}' {
			if state != ignore {
				stack--
			}
			i++
			continue
		}
		if in[i] == '>' {
			state = good
			i++
			continue
		}
		i++
	}
	return total
}

// Two .
func Two(in string) int {
	total := 0
	i := 0
	garbageStart := -1
	ignored := 0
	for i < len(in) {
		if in[i] == '<' {
			if garbageStart == -1 {
				garbageStart = i
				ignored = 0
			}
			i++
			continue
		}
		if in[i] == '!' {
			i += 2
			ignored++
			continue
		}
		if in[i] == '>' {
			total += i - garbageStart - 1 - ignored*2
			garbageStart = -1
			i++
			continue
		}
		i++
	}
	return total
}

func main() {
	f, _ := os.Open("./in")
	ins := ParseOne(f)
	fmt.Println(One(ins))
	fmt.Println(Two(ins))
}
