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
	scanner.Split(bufio.ScanLines)
	seen := make(map[int]int)
	for scanner.Scan() {
		n, _ := strconv.Atoi(scanner.Text())
		left := 2020 - n
		if _, found := seen[left]; found {
			return n * left
		}
		seen[n] = 1
	}
	return -1
}

// Two solution
func Two(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanLines)
	A := make([]int, 0)
	for scanner.Scan() {
		n, _ := strconv.Atoi(scanner.Text())
		A = append(A, n)
	}
	sort.Slice(A, func(i, j int) bool {
		return A[i] < A[j]
	})
	for i := 0; i < len(A); i++ {
		target := 2020 - A[i]
		lo := i + 1
		hi := len(A) - 1
		for lo < hi {
			if A[lo]+A[hi] == target {
				return A[lo] * A[hi] * A[i]
			}
			if A[lo]+A[hi] > target {
				hi--
			} else {
				lo++
			}
		}
	}
	return -1
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
