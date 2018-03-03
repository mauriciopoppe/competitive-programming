package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strings"
)

// ParseOne .
func ParseOne(r io.Reader) []string {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanLines)
	for scanner.Scan() {
		line := scanner.Text()
		return strings.Split(line, ",")
	}
	return nil
}

func spin(in string, program string) string {
	var n int
	fmt.Sscanf(program, "s%d", &n)
	runes := []rune(in)
	right := runes[len(in)-n:]
	left := runes[0 : len(in)-n]
	next := append(right, left...)
	return string(next)
}

func exchange(in string, program string) string {
	var l, r int
	fmt.Sscanf(program, "x%d/%d", &l, &r)
	runes := []rune(in)
	runes[l], runes[r] = runes[r], runes[l]
	return string(runes)
}

func partner(in string, program string) string {
	var p string
	fmt.Sscanf(program, "p%s", &p)
	runes := []rune(in)
	i := strings.Index(in, string(p[0]))
	j := strings.Index(in, string(p[2]))
	runes[i], runes[j] = runes[j], runes[i]
	return string(runes)
}

func eval(out string, program string) string {
	if program[0] == 's' {
		out = spin(out, program)
	} else if program[0] == 'x' {
		out = exchange(out, program)
	} else {
		out = partner(out, program)
	}
	return out
}

// One .
func One(out string, programs []string) string {
	for _, program := range programs {
		out = eval(out, program)
	}
	return out
}

func solveTwo(m map[string]int, loop int, hash string, programs []string) string {
	if start, ok := m[hash]; ok {
		offset := (int(1e9) % (loop - start)) - start
		for k, v := range m {
			if v == offset {
				return k
			}
		}
	}
	m[hash] = loop
	return solveTwo(m, loop+1, One(hash, programs), programs)
}

// Two .
func Two(out string, programs []string) string {
	m := make(map[string]int)
	return solveTwo(m, 0, out, programs)
}

func main() {
	f, _ := os.Open("./in")
	in := ParseOne(f)
	fmt.Println(One("abcdefghijklmnop", in))
	fmt.Println(Two("abcdefghijklmnop", in))
}
