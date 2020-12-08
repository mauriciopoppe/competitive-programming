package main

import (
	"bufio"
	"errors"
	"fmt"
	"io"
	"os"
	"strings"
)

func check(err error) {
	if err != nil {
		panic(err)
	}
}

func runProgram(program []string) (int, error) {
	acc := 0
	i := 0
	seen := make(map[int]bool)
	for i < len(program) {
		if _, ok := seen[i]; ok {
			return acc, errors.New("loop")
		}
		seen[i] = true
		var cmd string
		var op int
		_, err := fmt.Sscanf(program[i], "%s %d", &cmd, &op)
		check(err)
		if cmd == "acc" {
			acc += op
			i += 1
		}
		if cmd == "jmp" {
			i += op
		}
		if cmd == "nop" {
			i += 1
		}
	}

	return acc, nil
}

// One solution
func One(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	program := make([]string, 0)
	for scanner.Scan() {
		program = append(program, scanner.Text())
	}

	acc, _ := runProgram(program)
	return acc
}

// Two solution
func Two(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	program := make([]string, 0)
	for scanner.Scan() {
		program = append(program, scanner.Text())
	}

	for k, line := range program {
		old := program[k]
		if strings.Contains(line, "nop") {
			program[k] = strings.Replace(line, "nop", "jmp", -1)
		} else if strings.Contains(line, "jmp") {
			program[k] = strings.Replace(line, "jmp", "nop", -1)
		}
		acc, err := runProgram(program)
		if err == nil {
			return acc
		}
		program[k] = old
	}

	return -1
}

func main() {
	f, _ := os.Open("./in")
	defer f.Close()

	// rewind
	f.Seek(0, 0)
	fmt.Println(One(f))

	// rewind
	f.Seek(0, 0)
	fmt.Println(Two(f))
}
