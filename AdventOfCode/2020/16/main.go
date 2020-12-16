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

func getNums(s string) []int {
	tokens := strings.Split(s, ",")
	out := make([]int, 0)
	for _, v := range tokens {
		n, err := strconv.Atoi(v)
		check(err)
		out = append(out, n)
	}
	return out
}

type Rule struct {
	id   int
	word string
	ends [][]int
}

func (r *Rule) Parse(id int, line string) {
	var lo1, lo2, hi1, hi2 int
	tokens := strings.Split(line, ":")
	_, err := fmt.Sscanf(tokens[1], "%d-%d or %d-%d", &lo1, &hi1, &lo2, &hi2)
	check(err)
	r.id = id
	r.word = tokens[0]
	r.ends = append(r.ends, []int{lo1, hi1}, []int{lo2, hi2})
}

func (r *Rule) Ok(n int) bool {
	for _, pair := range r.ends {
		if pair[0] <= n && n <= pair[1] {
			return true
		}
	}
	return false
}

func (r *Rule) OkColumn(N []int) bool {
	valid := true
	for _, n := range N {
		if !r.Ok(n) {
			valid = false
		}
	}
	return valid
}

func (r *Rule) isDeparture() bool {
	return strings.HasPrefix(r.word, "departure")
}

// One solution
func One(r io.Reader) int {
	lines := getLines(r)
	rules := make([]Rule, 0)

	i := 0
	for i < len(lines) {
		if len(lines[i]) == 0 {
			break
		}

		r := Rule{}
		r.Parse(i, lines[i])
		rules = append(rules, r)
		i++
	}

	i += 2                // empty line + your ticket
	_ = getNums(lines[i]) // ignored on One
	i++

	i += 2 // empty line + nearby tickets
	nearbyTickets := make([]int, 0)
	for i < len(lines) {
		nearby := getNums(lines[i])
		nearbyTickets = append(nearbyTickets, nearby...)
		i++
	}
	//fmt.Println(rules, nearbyTickets)

	sum := 0
	for _, v := range nearbyTickets {
		valid := false
		for _, r := range rules {
			if r.Ok(v) {
				valid = true
			}
		}
		if !valid {
			//fmt.Println("invalid", v)
			sum += v
		}
	}

	return sum
}

func dfs(fulfills [][]int, iter int, solved *bool, order *[]int, m *map[int]bool) {
	//fmt.Println(*order)
	if *solved {
		return
	}
	if iter == len(fulfills) {
		fmt.Println("Solved!")
		*solved = true
		return
	}
	for _, v := range fulfills[iter] {
		if !(*m)[v] {
			(*m)[v] = true
			*order = append(*order, v)
			dfs(fulfills, iter+1, solved, order, m)
			if *solved {
				return
			}
			*order = (*order)[:len(*order)-1]
			(*m)[v] = false
		}
	}
}

// Two solution
func Two(r io.Reader) int64 {
	lines := getLines(r)
	rules := make([]Rule, 0)

	i := 0
	for i < len(lines) {
		if len(lines[i]) == 0 {
			break
		}
		r := Rule{}
		r.Parse(i, lines[i])
		rules = append(rules, r)
		i++
	}

	i += 2                          // empty line + your ticket
	yourTicket := getNums(lines[i]) // ignored on One
	i++

	i += 2 // empty line + nearby tickets
	nearbyTickets := make([][]int, len(rules))
	for i < len(lines) {
		j := 0
		for _, v := range getNums(lines[i]) {
			valid := false
			for _, r := range rules {
				if r.Ok(v) {
					valid = true
				}
			}
			if valid {
				nearbyTickets[j] = append(nearbyTickets[j], v)
			}
			j++
		}
		i++
	}

	fulfills := make([][]int, len(yourTicket))
	for i, column := range nearbyTickets {
		for _, r := range rules {
			if r.OkColumn(column) {
				fulfills[i] = append(fulfills[i], r.id)
			}
		}
	}

	order := make([]int, 0)
	taken := make(map[int]bool)
	solved := false
	dfs(fulfills, 0, &solved, &order, &taken)
	fmt.Println(order)

	var mult int64 = 1
	var total int64 = 0
	for i, _ := range yourTicket {
		r := rules[order[i]]
		if r.isDeparture() {
			total++
			mult *= int64(yourTicket[i])
		}
	}

	if total != 6 {
		panic("total should be 6")
	}

	return mult
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
