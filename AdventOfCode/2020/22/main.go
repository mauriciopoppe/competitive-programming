package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

func check(err error) {
	if err != nil {
		panic(err)
	}
}

func Read(r io.Reader) ([]int, []int) {
	scanner := bufio.NewScanner(r)
	A := make([]int, 0)
	B := make([]int, 0)
	for scanner.Scan() {
		str := scanner.Text()
		if len(str) == 0 {
			break
		}
		n, err := strconv.Atoi(str)
		if err == nil {
			A = append(A, n)
		}
	}
	for scanner.Scan() {
		str := scanner.Text()
		if len(str) == 0 {
			break
		}
		n, err := strconv.Atoi(str)
		if err == nil {
			B = append(B, n)
		}
	}
	return A, B
}

// One solution
func One(r io.Reader) int {
	A, B := Read(r)
	for len(A) > 0 && len(B) > 0 {
		a := A[0]
		A = A[1:]

		b := B[0]
		B = B[1:]

		if a > b {
			A = append(A, a, b)
		} else {
			B = append(B, b, a)
		}
	}

	out := A
	if len(out) == 0 {
		out = B
	}

	total := 0
	for i := 0; i < len(out); i++ {
		total += out[i] * (len(out) - i)
	}

	return total
}

func eq(A []int, B []int) bool {
	if len(A) != len(B) {
		return false
	}
	for i := 0; i < len(A); i++ {
		if A[i] != B[i] {
			return false
		}
	}
	return true
}

func seen(A []int, ha [][]int, B []int, hb [][]int) bool {
	for i := 0; i < len(ha); i++ {
		if eq(A, ha[i]) && eq(B, hb[i]) {
			return true
		}
	}
	return false
}

func Game(A []int, B []int, game int) (int, []int) {
	ha := make([][]int, 0)
	hb := make([][]int, 0)

	round := 1
	for len(A) > 0 && len(B) > 0 {
		round++
		if seen(A, ha, B, hb) {
			return 0, A
		}
		newA := A
		ha = append(ha, newA)
		a := A[0]
		A = A[1:]

		newB := B
		hb = append(hb, newB)
		b := B[0]
		B = B[1:]

		winner := 0
		if a <= len(A) && b <= len(B) {
			recA := make([]int, a)
			copy(recA, A[:a])
			recB := make([]int, b)
			copy(recB, B[:b])
			winner, _ = Game(recA, recB, game+1)
		} else {
			if a > b {
				winner = 0
			} else {
				winner = 1
			}
		}

		if winner == 0 {
			A = append(A, a, b)
		} else {
			B = append(B, b, a)
		}
	}
	if len(A) > 0 {
		return 0, A
	} else {
		return 1, B
	}
}

// Two solution
func Two(r io.Reader) int {
	A, B := Read(r)

	_, out := Game(A, B, 1)
	if len(out) == 0 {
		out = B
	}

	total := 0
	for i := 0; i < len(out); i++ {
		total += out[i] * (len(out) - i)
	}

	return total
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
