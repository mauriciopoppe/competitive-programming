package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func parse(r io.Reader) []string {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanLines)
	out := []string{}
	for scanner.Scan() {
		line := scanner.Text()
		out = append(out, line)
	}
	return out
}

func dfs(x int, y int, par int, in []string, visited [][]int, out *string, total *int) {
	visited[x][y] = 1
	dx := []int{0, -1, 0, 1}
	dy := []int{1, 0, -1, 0}
	*total = *total + 1

	if in[x][y] >= 'A' && in[x][y] <= 'Z' {
		*out = *out + string(in[x][y])
	}

	isValid := func(x int, y int) bool {
		return x >= 0 && y >= 0 && x < len(in) && y < len(in[x])
	}

	if in[x][y] != '+' {
		nx := x + dx[par]
		ny := y + dy[par]
		if isValid(nx, ny) && in[nx][ny] != ' ' {
			dfs(nx, ny, par, in, visited, out, total)
		}
		return
	}

	for i := 0; i < 4; i++ {
		nx := x + dx[i]
		ny := y + dy[i]
		// fmt.Println("test ", i, nx, ny, isValid(nx, ny), in[nx][ny] != ' ')
		if isValid(nx, ny) && in[nx][ny] != ' ' && visited[nx][ny] == 0 {
			dfs(nx, ny, i, in, visited, out, total)
		}
	}
}

// OneTwo (solves both one and two)
func OneTwo(in []string) (string, int) {
	var out string
	visited := [][]int{}
	for _, line := range in {
		visited = append(visited, make([]int, len(line)))
	}
	total := 0
	for j := range in[0] {
		if in[0][j] != ' ' {
			dfs(0, j, 3, in, visited, &out, &total)
		}
	}
	return out, total
}

func main() {
	f, _ := os.Open("./in")
	defer f.Close()

	in := parse(f)
	fmt.Println(OneTwo(in))
}
