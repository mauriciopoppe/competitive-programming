package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
	"strconv"
)

func check(err error) {
	if err != nil {
		panic(err)
	}
}

// One solution
func One(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	A := make([]int, 0)
	mx := 0
	for scanner.Scan() {
		n, _ := strconv.Atoi(scanner.Text())
		if n > mx {
			mx = n
		}
		A = append(A, n)
	}
	A = append(A, 0, mx+3)

	sort.Slice(A, func(i, j int) bool {
		return A[i] < A[j]
	})

	ones := 0
	three := 0
	for i := 1; i < len(A); i++ {
		if A[i]-A[i-1] == 1 {
			ones++
		}
		if A[i]-A[i-1] == 3 {
			three++
		}
	}

	return ones * three
}

// Two solution
func Two(r io.Reader) int64 {
	scanner := bufio.NewScanner(r)
	E := make(map[int]bool)
	mx := 0
	for scanner.Scan() {
		n, _ := strconv.Atoi(scanner.Text())
		if n > mx {
			mx = n
		}
		E[n] = true
	}

	mx += 3
	dp := make([]int64, mx+1)
	E[0] = true
	dp[0] = 1

	for i := 1; i <= mx; i++ {
		for k := 1; k <= 3; k++ {
			if _, ok := E[i-k]; ok {
				dp[i] += dp[i-k]
			}
		}
	}

	return dp[mx]
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
