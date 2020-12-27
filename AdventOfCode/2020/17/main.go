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

type Point struct {
	x, y, z, w int
}

const (
	ACTIVE = iota
	INACTIVE
)

// One solution
func One(r io.Reader) int {
	scanner := bufio.NewScanner(r)

	M := make(map[Point]int)

	y := 0
	for scanner.Scan() {
		line := scanner.Text()
		x := 0
		for _, r := range line {
			if r == '#' {
				M[Point{x, y, 0, 0}] = ACTIVE
			}
			x++
		}
		y++
	}

	ans := 0
	for iter := 0; iter < 6; iter++ {
		N := make(map[Point]int)
		ans = 0

		for s, _ := range M {
			for x := -1; x <= 1; x++ {
				for y := -1; y <= 1; y++ {
					for z := -1; z <= 1; z++ {
						nextS := Point{s.x + x, s.y + y, s.z + z, 0}
						v := countActive3(M, nextS)
						if _, ok := M[nextS]; ok && (v == 2 || v == 3) {
							N[nextS] = ACTIVE
						}
						if _, ok := M[nextS]; !ok && v == 3 {
							N[nextS] = ACTIVE
						}
					}
				}
			}
		}

		M = make(map[Point]int)
		for k, _ := range N {
			M[k] = ACTIVE
		}
		ans = len(M)
	}

	return ans
}

// Two solution
func Two(r io.Reader) int {
	scanner := bufio.NewScanner(r)

	M := make(map[Point]int)

	y := 0
	for scanner.Scan() {
		line := scanner.Text()
		x := 0
		for _, r := range line {
			if r == '#' {
				M[Point{x, y, 0, 0}] = ACTIVE
			}
			x++
		}
		y++
	}

	ans := 0
	for iter := 0; iter < 6; iter++ {
		N := make(map[Point]int)
		ans = 0

		for s, _ := range M {
			for x := -1; x <= 1; x++ {
				for y := -1; y <= 1; y++ {
					for z := -1; z <= 1; z++ {
						for w := -1; w <= 1; w++ {
							nextS := Point{s.x + x, s.y + y, s.z + z, s.w + w}
							v := countActive4(M, nextS)
							if _, ok := M[nextS]; ok && (v == 2 || v == 3) {
								N[nextS] = ACTIVE
							}
							if _, ok := M[nextS]; !ok && v == 3 {
								N[nextS] = ACTIVE
							}
						}
					}
				}
			}
		}

		M = make(map[Point]int)
		for k, _ := range N {
			M[k] = ACTIVE
		}
		ans = len(M)
	}

	return ans
}

func countActive3(m map[Point]int, s Point) int {
	count := 0
	for x := -1; x <= 1; x++ {
		for y := -1; y <= 1; y++ {
			for z := -1; z <= 1; z++ {
				if x == 0 && y == 0 && z == 0 {
					continue
				}
				nS := Point{s.x + x, s.y + y, s.z + z, 0}
				if _, ok := m[nS]; ok {
					count++
				}
			}
		}
	}
	return count
}

func countActive4(m map[Point]int, s Point) int {
	count := 0
	for x := -1; x <= 1; x++ {
		for y := -1; y <= 1; y++ {
			for z := -1; z <= 1; z++ {
				for w := -1; w <= 1; w++ {
					if x == 0 && y == 0 && z == 0 && w == 0 {
						continue
					}
					nS := Point{s.x + x, s.y + y, s.z + z, s.w + w}
					if _, ok := m[nS]; ok {
						count++
					}
				}
			}
		}
	}
	return count
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
