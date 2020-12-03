package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func check(err error) {
	if err != nil {
		panic(err)
	}
}

// One solution
func One(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	var grid []string
	for scanner.Scan() {
		grid = append(grid, scanner.Text())
	}
	rows := len(grid)
	cols := len(grid[0])

	cnt := 0
	j := 0
	for i := 0; i < rows; i++ {
		if grid[i][j] == '#' {
			cnt++
		}
		j += 3
		j %= cols
	}

	return cnt
}

// Two solution
func Two(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	var grid []string
	for scanner.Scan() {
		grid = append(grid, scanner.Text())
	}
	rows := len(grid)
	cols := len(grid[0])

	type Point struct {
		y, x int
	}

	best := 1
	locs := []Point{{1, 1}, {3, 1}, {5, 1}, {7, 1}, {1, 2}}
	for _, p := range locs {
		cnt := 0
		j := 0
		for i := 0; i < rows; i += p.x {
			if grid[i][j] == '#' {
				cnt++
			}
			j += p.y
			j %= cols
		}
		best *= cnt
	}

	return best
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
