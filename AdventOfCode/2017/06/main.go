package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func arrayToString(a []int, delim string) string {
	return strings.Trim(strings.Replace(fmt.Sprint(a), " ", delim, -1), "[]")
}

// One sol
func One(v []int) int {
	m := make(map[string]bool)
	total := 0
	for {
		str := arrayToString(v, ",")
		if m[str] {
			return total
		}
		m[str] = true
		total++
		maxi := 0
		for i := range v {
			if v[i] > v[maxi] {
				maxi = i
			}
		}
		toSub := v[maxi]
		v[maxi] = 0
		for i := 0; i < toSub; i++ {
			maxi = (maxi + 1) % len(v)
			v[maxi]++
		}
	}
}

// Two sol
func Two(v []int) int {
	m := make(map[string]int)
	total := 0
	for {
		str := arrayToString(v, ",")
		if last, k := m[str]; k {
			return total - last
		}
		m[str] = total
		total++
		maxi := 0
		for i := range v {
			if v[i] > v[maxi] {
				maxi = i
			}
		}
		toSub := v[maxi]
		v[maxi] = 0
		for i := 0; i < toSub; i++ {
			maxi = (maxi + 1) % len(v)
			v[maxi]++
		}
	}
}
func parse(r io.Reader) []int {
	scanner := bufio.NewScanner(r)
	v := make([]int, 0)
	scanner.Scan()
	line := scanner.Text()
	for _, vi := range strings.Fields(line) {
		n, _ := strconv.Atoi(vi)
		v = append(v, n)
	}
	return v
}

func main() {
	f, _ := os.Open("./in")
	v := parse(f)
	fmt.Println(One(v))
	fmt.Println(Two(v))
}
