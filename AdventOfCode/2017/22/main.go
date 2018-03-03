package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

// Point .
type Point struct {
	x int
	y int
}

func printMatrix(in [][]byte) {
	for i := range in {
		fmt.Println(string(in[i]))
	}
	fmt.Println("")
}

func parse(r io.Reader) (map[Point]byte, int, int) {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanLines)
	out := make(map[Point]byte)
	i := 0
	var y int
	for scanner.Scan() {
		line := scanner.Text()
		y = len(line) / 2
		for j := range line {
			out[Point{i, j}] = line[j]
		}
		i++
	}
	return out, i / 2, y
}

// One .
func One(in map[Point]byte, x int, y int) int {
	dx := []int{0, -1, 0, 1}
	dy := []int{-1, 0, 1, 0}
	dir := 1

	next := make(map[byte]byte)
	next['#'] = '.'
	next['.'] = '#'

	total := 0
	for i := 0; i < 10000; i++ {
		old, ok := in[Point{x, y}]
		if !ok {
			old = '.'
		}
		if old == '#' {
			dir = (dir + 1) % 4
		} else {
			dir = (dir - 1 + 4) % 4
			total++
		}
		in[Point{x, y}] = next[old]
		x += dx[dir]
		y += dy[dir]
	}

	return total
}

// Two .
func Two(in map[Point]byte, x int, y int) int {
	dx := []int{0, -1, 0, 1}
	dy := []int{-1, 0, 1, 0}
	dir := 1

	next := make(map[byte]byte)
	next['.'] = 'w'
	next['w'] = '#'
	next['#'] = 'f'
	next['f'] = '.'

	total := 0
	for i := 0; i < int(1e7); i++ {
		old, ok := in[Point{x, y}]
		if !ok {
			old = '.'
		}
		if old == '.' {
			dir = (dir - 1 + 4) % 4
		} else if old == 'f' {
			dir = (dir + 2) % 4
		} else if old == '#' {
			dir = (dir + 1) % 4
		} else {
			total++
		}
		in[Point{x, y}] = next[old]
		x += dx[dir]
		y += dy[dir]
	}

	return total
}

func main() {
	// f, _ := os.Open("./in-sample")
	f, _ := os.Open("./in")
	defer f.Close()

	in, x, y := parse(f)
	in2 := make(map[Point]byte)
	for k, v := range in {
		in2[k] = v
	}
	fmt.Println(One(in, x, y))
	fmt.Println(Two(in2, x, y))
}
