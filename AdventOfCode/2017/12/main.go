package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strings"
)

// ParseOne .
func ParseOne(r io.Reader) map[int][]int {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanLines)
	m := make(map[int][]int)
	for scanner.Scan() {
		line := scanner.Text()
		var u int
		fmt.Sscanf(line, "%d", &u)
		nums := string(line[strings.Index(line, "<->")+3:])
		for _, vs := range strings.Split(nums, ",") {
			var v int
			fmt.Sscanf(vs, "%d", &v)
			m[u] = append(m[u], v)
		}
	}
	return m
}

func dfs(visited map[int]bool, m map[int][]int, n int, total *int) {
	visited[n] = true
	*total = *total + 1
	for _, v := range m[n] {
		if !visited[v] {
			dfs(visited, m, v, total)
		}
	}
}

// One .
func One(m map[int][]int) int {
	total := 0
	visited := make(map[int]bool)
	dfs(visited, m, 0, &total)
	return total
}

// Two .
func Two(m map[int][]int) int {
	total := 0
	cnt := 0
	visited := make(map[int]bool)
	for k := range m {
		if !visited[k] {
			dfs(visited, m, k, &total)
			cnt++
		}
	}
	return cnt
}

func main() {
	f, _ := os.Open("./in")
	in := ParseOne(f)
	fmt.Println(One(in))
	fmt.Println(Two(in))
}
