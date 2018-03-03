package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

func solveOne(n int) (int, int) {
	var nx, ny int = 0, 0
	dx := []int{1, 0, -1, 0}
	dy := []int{0, 1, 0, -1}
	dir := 0
	steps := 1
	for {
		for k := 0; k < 2; k++ {
			for j := 0; j < steps; j++ {
				n--
				if n == 0 {
					return nx, ny
				}
				// fmt.Println(nx, ny)
				nx += dx[dir]
				ny += dy[dir]
			}
			dir = (dir + 1) % 4
		}
		steps++
	}
}

func pos(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// One sol
func One(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanLines)
	for scanner.Scan() {
		line := scanner.Text()
		n, _ := strconv.Atoi(line)
		x, y := solveOne(n)
		return pos(x) + pos(y)
	}
	return -1
}

// Coord a coord
type Coord struct {
	x, y int
}

func solveTwo(n int) int {
	var nx, ny int = 0, 0
	m := make(map[Coord]int)
	dx := []int{1, 0, -1, 0}
	dy := []int{0, 1, 0, -1}
	arx := []int{0, -1, -1, -1, 0, 1, 1, 1}
	ary := []int{1, 1, 0, -1, -1, -1, 0, 1}
	m[Coord{0, 0}] = 1
	dir := 0
	steps := 1
	for {
		for k := 0; k < 2; k++ {
			for j := 0; j < steps; j++ {
				next := 0
				// fmt.Println(nx, ny)
				nx += dx[dir]
				ny += dy[dir]
				for z := 0; z < 8; z++ {
					cx := nx + arx[z]
					cy := ny + ary[z]
					v, ok := m[Coord{cx, cy}]
					if ok {
						next += v
					}
				}
				// fmt.Println(nx, ny, next)
				m[Coord{nx, ny}] = next
				if next > n {
					return next
				}
			}
			dir = (dir + 1) % 4
		}
		steps++
	}
}

// Two sol
func Two(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanLines)
	for scanner.Scan() {
		line := scanner.Text()
		n, _ := strconv.Atoi(line)
		return solveTwo(n)
	}
	return -1
}

func main() {
	f, _ := os.Open("./in")

	f.Seek(0, 0)
	fmt.Println(One(f))

	f.Seek(0, 0)
	fmt.Println(Two(f))
}
