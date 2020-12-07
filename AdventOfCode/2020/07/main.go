package main

import (
	"bufio"
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

// One solution
func One(r io.Reader) int {
	scanner := bufio.NewScanner(r)

	graph := make(map[string]map[string]int)
	total := 0

	for scanner.Scan() {
		line := scanner.Text()
		var a, b string
		var err error
		tokens := strings.Split(line, "contain")
		if len(tokens) != 2 {
			panic("expecting 2")
		}
		_, err = fmt.Sscanf(tokens[0], "%s %s", &a, &b)
		to := a + b
		check(err)

		rightBags := strings.Split(tokens[1], ",")
		var nBags int
		for _, rightBag := range rightBags {
			if strings.Contains(rightBag, "no") {
				break
			}
			_, err = fmt.Sscanf(rightBag, "%d %s %s", &nBags, &a, &b)
			from := a + b
			check(err)

			if _, ok := graph[from]; !ok {
				graph[from] = make(map[string]int)
			}

			//fmt.Println(from, to)
			graph[from][to] = nBags
		}
	}

	visited := make(map[string]bool)
	q := make([]string, 0)
	q = append(q, "shinygold")
	for i := 0; i < len(q); i++ {
		top := q[i]
		if _, ok := visited[top]; ok {
			continue
		}
		visited[top] = true
		total++
		for k, _ := range graph[top] {
			if _, ok := visited[k]; !ok {
				q = append(q, k)
			}
		}
	}
	return total - 1
}

func dfs(graph map[string]map[string]int, from string) int {
	total := 0
	for to, v := range graph[from] {
		total += v + v*dfs(graph, to)
	}
	return total
}

// Two solution
func Two(r io.Reader) int {
	scanner := bufio.NewScanner(r)

	graph := make(map[string]map[string]int)
	for scanner.Scan() {
		line := scanner.Text()
		var a, b string
		var err error
		tokens := strings.Split(line, "contain")
		if len(tokens) != 2 {
			panic("expecting 2")
		}
		_, err = fmt.Sscanf(tokens[0], "%s %s", &a, &b)
		from := a + b
		check(err)

		rightBags := strings.Split(tokens[1], ",")
		var nBags int
		for _, rightBag := range rightBags {
			if strings.Contains(rightBag, "no") {
				break
			}
			_, err = fmt.Sscanf(rightBag, "%d %s %s", &nBags, &a, &b)
			to := a + b
			check(err)

			if _, ok := graph[from]; !ok {
				graph[from] = make(map[string]int)
			}

			//fmt.Println(from, to)
			graph[from][to] = nBags
		}
	}

	return dfs(graph, "shinygold")
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
