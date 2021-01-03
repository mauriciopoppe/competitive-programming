package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func check(err error) {
	if err != nil {
		panic(err)
	}
}

func getLines(r io.Reader) []string {
	scanner := bufio.NewScanner(r)
	lines := make([]string, 0)
	for scanner.Scan() {
		lines = append(lines, scanner.Text())
	}
	return lines
}

func Parse(C map[int]uint8, R map[int][][]int, str string) {
	ruleStr := strings.Split(str, ":")

	n, err := strconv.Atoi(ruleStr[0])
	check(err)

	options := ruleStr[1]
	if strings.Contains(options, "\"") {
		index := strings.Index(options, "\"") + 1
		C[n] = options[index]
	} else {
		rules := strings.Split(options, "|")
		for _, rule := range rules {
			nums := strings.Split(rule, " ")
			r := make([]int, 0)
			for _, nStr := range nums {
				if len(nStr) == 0 {
					continue
				}
				innerN, innerErr := strconv.Atoi(nStr)
				check(innerErr)
				r = append(r, innerN)
			}
			R[n] = append(R[n], r)
		}
	}
}

type State struct {
	i, j, id int
}

func matchAll(C map[int]uint8, R map[int][][]int, dp map[State]bool, s string, i int, j int, rules []int) bool {
	if i == j && len(rules) == 0 {
		return true
	}
	if i == j || len(rules) == 0 {
		return false
	}

	for k := i + 1; k <= j; k++ {
		if matchSingle(C, R, dp, s, i, k, rules[0]) && matchAll(C, R, dp, s, k, j, rules[1:]) {
			return true
		}
	}
	return false
}

func matchSingle(C map[int]uint8, R map[int][][]int, dp map[State]bool, s string, i int, j int, rule int) bool {
	state := State{i, j, rule}
	if v, ok := dp[state]; ok {
		return v
	}

	ret := false
	if v, ok := C[rule]; ok {
		ret = i == j-1 && s[i] == v
	} else {
		for _, option := range R[rule] {
			if matchAll(C, R, dp, s, i, j, option) {
				ret = true
				break
			}
		}
	}

	dp[state] = ret
	return ret
}

// One solution
func One(r io.Reader) int {
	lines := getLines(r)
	R := make(map[int][][]int)
	C := make(map[int]uint8)

	i := 0
	for i < len(lines) && len(lines[i]) > 0 {
		Parse(C, R, lines[i])
		i++
	}

	i++ // skip empty line
	total := 0
	for i < len(lines) {
		dp := make(map[State]bool)
		if solved := matchSingle(C, R, dp, lines[i], 0, len(lines[i]), 0); solved {
			total++
		}
		i++
	}
	return total
}

// Two solution
func Two(r io.Reader) int {
	lines := getLines(r)
	R := make(map[int][][]int)
	C := make(map[int]uint8)

	i := 0
	for i < len(lines) && len(lines[i]) > 0 {
		Parse(C, R, lines[i])
		i++
	}
	R[8] = make([][]int, 0)
	R[8] = append(R[8], []int{42}, []int{42, 8})
	R[11] = make([][]int, 0)
	R[11] = append(R[11], []int{42, 31}, []int{42, 11, 31})

	i++ // skip empty line
	total := 0
	for i < len(lines) {
		dp := make(map[State]bool)
		if solved := matchSingle(C, R, dp, lines[i], 0, len(lines[i]), 0); solved {
			total++
		}
		i++
	}
	return total
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
