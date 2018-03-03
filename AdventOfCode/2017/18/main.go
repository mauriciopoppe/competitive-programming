package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
	"time"
)

// ParseOne .
func ParseOne(r io.Reader) []string {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanLines)
	out := make([]string, 0)
	for scanner.Scan() {
		line := scanner.Text()
		out = append(out, line)
	}
	return out
}

func getReg(s string, reg []int64) int64 {
	n, err := strconv.Atoi(s)
	if err != nil {
		n = int(s[0] - 'a')
	}
	return int64(n)
}

func getVal(s string, reg []int64) int64 {
	if s[0] < 'a' || s[0] > 'z' {
		n, _ := strconv.Atoi(s)
		return int64(n)
	}
	return reg[s[0]-'a']
}

// One .
func One(in [][]string) int64 {
	reg := make([]int64, 26)
	var lastPlay int64
	i := 0
	lastPlay = 0
	for i < len(in) {
		switch in[i][0] {
		case "snd":
			X := getVal(in[i][1], reg)
			lastPlay = X
			i++
		case "set":
			X := getReg(in[i][1], reg)
			Y := getVal(in[i][2], reg)
			reg[X] = Y
			i++
		case "add":
			X := getReg(in[i][1], reg)
			Y := getVal(in[i][2], reg)
			reg[X] += Y
			i++
		case "mul":
			X := getReg(in[i][1], reg)
			Y := getVal(in[i][2], reg)
			reg[X] *= Y
			i++
		case "mod":
			X := getReg(in[i][1], reg)
			Y := getVal(in[i][2], reg)
			reg[X] %= Y
			i++
		case "rcv":
			X := getVal(in[i][1], reg)
			if X != 0 {
				return lastPlay
			}
			i++
		case "jgz":
			X := getVal(in[i][1], reg)
			Y := getVal(in[i][2], reg)
			if X != 0 {
				i += int(Y)
			} else {
				i++
			}
		}
	}
	return -1
}

func get(registers map[string]int, op string) int {
	n, err := strconv.Atoi(op)
	if err == nil {
		return n
	}
	return registers[op]
}

func runTwo(in []string, id int, rec chan int, snd chan int, sends *int) {
	pos := 0
	registers := make(map[string]int)
	registers["p"] = id
	for pos >= 0 && pos < len(in) {
		// if id == 0 {
		// 	fmt.Println("a", registers, rec, snd)
		// }
		op := strings.Fields(in[pos])
		switch op[0] {
		case "snd":
			snd <- get(registers, op[1])
			*sends++
		case "set":
			registers[op[1]] = get(registers, op[2])
		case "add":
			registers[op[1]] += get(registers, op[2])
		case "mul":
			registers[op[1]] *= get(registers, op[2])
		case "mod":
			registers[op[1]] %= get(registers, op[2])
		case "rcv":
			a := <-rec
			registers[op[1]] = a
		case "jgz":
			if get(registers, op[1]) > 0 {
				pos += get(registers, op[2])
				continue
			}
		}
		pos++
	}
}

// Two .
func Two(in []string) int {
	p1 := make(chan int, 1000)
	p2 := make(chan int, 1000)
	sends := make([]int, 2)
	go runTwo(in, 0, p1, p2, &sends[0])
	go runTwo(in, 1, p2, p1, &sends[1])

	for {
		time.Sleep(1000 * time.Millisecond)
		if len(p1) == 0 && len(p2) == 0 {
			break
		}
	}
	return sends[1]
}

func main() {
	f, _ := os.Open("./in")
	defer f.Close()
	// f, _ := os.Open("./in-sample-2")
	in := ParseOne(f)
	// fmt.Println(One(in))
	fmt.Println(Two(in))
}
