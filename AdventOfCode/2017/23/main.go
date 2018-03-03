package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

// parse .
func parse(r io.Reader) []string {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanLines)
	out := make([]string, 0)
	for scanner.Scan() {
		line := scanner.Text()
		out = append(out, line)
	}
	return out
}

func get(registers map[string]int, op string) int {
	n, err := strconv.Atoi(op)
	if err == nil {
		return n
	}
	return registers[op]
}

// One .
func One(in []string) int {
	reg := make(map[string]int)
	i := 0
	total := 0
	for i < len(in) {
		// fmt.Println(i+1, printReg(reg), in[i])
		op := strings.Fields(in[i])
		switch op[0] {
		case "set":
			reg[op[1]] = get(reg, op[2])
		case "sub":
			reg[op[1]] -= get(reg, op[2])
		case "mul":
			reg[op[1]] *= get(reg, op[2])
			total++
		case "jnz":
			if get(reg, op[1]) != 0 {
				i += get(reg, op[2])
				continue
			}
		}
		i++
	}
	return total
}

func printReg(reg map[string]int) string {
	var inline string
	for i := 'a'; i <= 'h'; i++ {
		inline = inline + fmt.Sprintf("%c=%7d; ", i, reg[string(i)])
	}
	return inline
}

// Two .
func Two(in []string, maxIter int) int {
	reg := make(map[string]int)
	i := 0
	reg["a"] = 1
	iter := 0
	for i < len(in) {
		fmt.Println(i+1, printReg(reg), in[i])
		iter++
		if iter > maxIter {
			break
		}
		op := strings.Fields(in[i])
		switch op[0] {
		case "set":
			reg[op[1]] = get(reg, op[2])
		case "sub":
			reg[op[1]] -= get(reg, op[2])
		case "mul":
			reg[op[1]] *= get(reg, op[2])
		case "mod":
			reg[op[1]] %= get(reg, op[2])
		case "div":
			reg[op[1]] /= get(reg, op[2])
		case "jnz":
			if get(reg, op[1]) != 0 {
				i += get(reg, op[2])
				continue
			}
		}
		i++
	}
	return reg["h"]
}

// TwoClever .
func TwoClever() int {
	b := 107900
	c := 124900
	isProd := func(n int) int {
		for i := 2; i*i <= n; i++ {
			complement := n / i
			if i*complement-n == 0 {
				return 1
			}
		}
		return 0
	}
	total := 0
	for i := b; i <= c; i += 17 {
		total += isProd(i)
	}
	return total
}

func main() {
	f, _ := os.Open("./in")
	defer f.Close()
	in := parse(f)
	fmt.Println(One(in))

	// f2, _ := os.Open("./in2")
	// defer f2.Close()
	// in2 := parse(f2)
	fmt.Println(TwoClever())
}
