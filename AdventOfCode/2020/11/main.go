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

func cnt(m [][]rune, i int, j int, want rune) int {
	total := 0
	for x := i - 1; x <= i+1; x++ {
		for y := j - 1; y <= j+1; y++ {
			if x == i && y == j {
				continue
			}
			if x < 0 || x >= len(m) || y < 0 || y >= len(m[0]) {
				continue
			}
			if m[x][y] == want {
				total++
			}
		}
	}
	return total
}

func cnt2(m [][]rune, i int, j int, want rune) int {
	total := 0
	x := []int{-1, -1, -1, 0, 0, 1, 1, 1}
	y := []int{-1, 0, 1, -1, 1, -1, 0, 1}

	for k := 0; k < 8; k++ {
		for mult := 1; ; mult++ {
			nx := i + x[k]*mult
			ny := j + y[k]*mult
			if nx < 0 || nx >= len(m) || ny < 0 || ny >= len(m[0]) {
				break
			}
			if m[nx][ny] != '.' {
				if m[nx][ny] == want {
					total++
				}
				break
			}
		}
	}
	return total
}

func clone(A [][]rune) [][]rune {
	n := len(A)
	m := len(A[0])
	duplicate := make([][]rune, n)
	data := make([]rune, n*m)
	for i := range A {
		start := i * m
		end := start + m
		duplicate[i] = data[start:end:end]
		copy(duplicate[i], A[i])
	}
	return duplicate
}

// One solution
func One(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	A := make([][]rune, 0)
	for scanner.Scan() {
		line := scanner.Text()
		A = append(A, []rune(line))
	}
	B := clone(A)
	R := len(A)
	C := len(A[0])

	rounds := 0
	want := 0
	for ; ; rounds++ {
		want = 0
		for i := 0; i < R; i++ {
			for j := 0; j < C; j++ {
				if A[i][j] == 'L' {
					if cnt(A, i, j, '#') == 0 {
						B[i][j] = '#'
					}
				}
				if A[i][j] == '#' {
					if cnt(A, i, j, '#') >= 4 {
						B[i][j] = 'L'
					}
				}
			}
		}

		diff := 0
		for i := 0; i < R; i++ {
			for j := 0; j < C; j++ {
				if A[i][j] != B[i][j] {
					diff++
				}
				if B[i][j] == '#' {
					want++
				}
			}
		}

		if diff == 0 {
			break
		}
		A = B
		B = clone(A)
	}

	return want
}

// Two solution
func Two(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	A := make([][]rune, 0)
	for scanner.Scan() {
		line := scanner.Text()
		A = append(A, []rune(line))
	}
	B := clone(A)
	R := len(A)
	C := len(A[0])

	rounds := 0
	want := 0
	for ; ; rounds++ {
		want = 0
		diff := 0

		for i := 0; i < R; i++ {
			for j := 0; j < C; j++ {
				if A[i][j] == 'L' {
					if cnt2(A, i, j, '#') == 0 {
						B[i][j] = '#'
						diff++
					}
				}
				if A[i][j] == '#' {
					if cnt2(A, i, j, '#') >= 5 {
						B[i][j] = 'L'
						diff++
					}
				}

				if B[i][j] == '#' {
					want++
				}
			}
		}

		if diff == 0 {
			break
		}
		A = B
		B = clone(A)
	}

	return want
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
