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

func abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}

// One solution
func One(r io.Reader) int {
	scanner := bufio.NewScanner(r)

	dy := []int{0, -1, 0, 1}
	dx := []int{1, 0, -1, 0}
	x := 0
	y := 0
	dir := 0

	for scanner.Scan() {
		line := scanner.Text()
		var cmd rune
		var op int
		_, err := fmt.Sscanf(line, "%c%d", &cmd, &op)
		check(err)
		if cmd == 'N' {
			y += op
		} else if cmd == 'S' {
			y -= op
		} else if cmd == 'E' {
			x += op
		} else if cmd == 'W' {
			x -= op
		} else if cmd == 'R' {
			for op > 0 {
				dir = (dir + 1) % 4
				op -= 90
			}
		} else if cmd == 'L' {
			for op > 0 {
				dir--
				if dir < 0 {
					dir = 3
				}
				op -= 90
			}
		} else if cmd == 'F' {
			x += op * dx[dir]
			y += op * dy[dir]
		}

		//fmt.Println(x, y)
	}
	return abs(x) + abs(y)
}

// Two solution
func Two(r io.Reader) int {
	scanner := bufio.NewScanner(r)

	wx := 10
	wy := 1
	x := 0
	y := 0

	for scanner.Scan() {
		line := scanner.Text()
		var cmd rune
		var op int
		_, err := fmt.Sscanf(line, "%c%d", &cmd, &op)
		check(err)
		if cmd == 'N' {
			wy += op
		} else if cmd == 'S' {
			wy -= op
		} else if cmd == 'E' {
			wx += op
		} else if cmd == 'W' {
			wx -= op
		} else if cmd == 'R' {
			dx := wx - x
			dy := wy - y
			for op > 0 {
				dx, dy = dy, -dx
				op -= 90
				/*
				   [0  1][x
				   -1  0][y
				*/
			}
			wx = dx + x
			wy = dy + y
		} else if cmd == 'L' {
			dx := wx - x
			dy := wy - y
			for op > 0 {
				dx, dy = -dy, dx
				op -= 90
				/*
				   [0  -1][x
				    1  0][y
				*/
			}
			wx = dx + x
			wy = dy + y
		} else if cmd == 'F' {
			dx := wx - x
			dy := wy - y
			wx -= x
			wy -= y
			x += dx * op
			y += dy * op
			wx += x
			wy += y
		}

		//fmt.Println(wx - x, wy - y)
		//fmt.Println(x, y)
		//fmt.Println()
	}
	return abs(x) + abs(y)
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
