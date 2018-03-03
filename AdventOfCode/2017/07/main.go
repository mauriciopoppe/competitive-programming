package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strings"
)

// ParseOne sol
func ParseOne(r io.Reader) ([]string, map[string]int) {
	s := make([]string, 0)
	m := make(map[string]int)
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanLines)
	for scanner.Scan() {
		line := scanner.Text()
		words := strings.Fields(line)
		key := words[0]
		s = append(s, key)
		for i := 3; i < len(words); i++ {
			cand := words[i]
			if i != len(words)-1 {
				cand = cand[:len(cand)-1]
			}
			m[cand]++
		}
	}
	return s, m
}

// ParseTwo sol
func ParseTwo(r io.Reader) (map[string]int, map[string][]string) {
	s := make(map[string]int)
	m := make(map[string][]string)
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanLines)
	for scanner.Scan() {
		line := scanner.Text()
		words := strings.Fields(line)
		var key string
		var id int
		fmt.Sscanf(line, "%s (%d)", &key, &id)
		s[key] = id
		for i := 3; i < len(words); i++ {
			cand := words[i]
			if i != len(words)-1 {
				cand = cand[:len(cand)-1]
			}
			m[key] = append(m[key], cand)
		}
		// fmt.Println(s)
	}
	return s, m
}

// One sol
func One(s []string, m map[string]int) string {
	for _, str := range s {
		if v := m[str]; v == 0 {
			return str
		}
	}
	return ""
}

func abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}

func findDiff(n []int) int {
	m := make(map[int]int)
	for i := 0; i < len(n); i++ {
		m[n[i]]++
	}
	if len(m) > 1 {
		c := make([]int, 0)
		for k := range m {
			c = append(c, k)
		}
		return abs(c[0] - c[1])
	}
	return -1
}

func rec(cur string, s map[string]int, m map[string][]string) (bool, int) {
	total := s[cur]
	cmp := make([]int, len(m[cur]))
	for i, str := range m[cur] {
		valid, n := rec(str, s, m)
		if !valid {
			return false, n
		}
		cmp[i] = n
		total += n
	}
	diff := findDiff(cmp)
	if diff != -1 {
		return false, diff
	}
	return true, total
}

// Two sol
func Two(solOne string, s map[string]int, m map[string][]string) int {
	_, n := rec(solOne, s, m)
	var valid bool
	for k := range s {
		s[k] += n
		valid, _ = rec(solOne, s, m)
		if valid {
			return s[k]
		}
		s[k] -= 2 * n
		valid, _ = rec(solOne, s, m)
		if valid {
			return s[k]
		}
		s[k] += n
	}
	return -1
}

func main() {
	f, _ := os.Open("./in")

	f.Seek(0, 0)
	s, m := ParseOne(f)
	solOne := One(s, m)
	fmt.Println(solOne)

	f.Seek(0, 0)
	s2, m2 := ParseTwo(f)
	fmt.Println(Two(solOne, s2, m2))
}
