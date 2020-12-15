package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func check(err error) {
	if err != nil {
		panic(err)
	}
}

// One solution
func One(r io.Reader, limit int) int {
	scanner := bufio.NewScanner(r)
	spoken := make(map[int]int)
	seen := make(map[int][]int)

	for scanner.Scan() {
		tokens := strings.Split(scanner.Text(), ",")

		for i, tok := range tokens {
			n, err := strconv.Atoi(tok)
			check(err)
			spoken[i+1] = n
			seen[n] = append(seen[n], i+1)
		}

		for i := len(tokens) + 1; i <= limit; i++ {
			lastSpoken := spoken[i-1]
			A := seen[lastSpoken]
			if len(seen[lastSpoken]) >= 2 {
				spoken[i] = A[len(A)-1] - A[len(A)-2]
				seen[spoken[i]] = append(seen[spoken[i]], i)
			} else {
				spoken[i] = 0
				seen[0] = append(seen[0], i)
			}
		}

	}
	return spoken[limit]
}

// Two solution
func Two(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	for scanner.Scan() {
	}
	return -1
}

func main() {
	f, _ := os.Open("./in")
	defer f.Close()

	// rewind
	f.Seek(0, 0)
	fmt.Println(One(f, 2020))

	// rewind
	f.Seek(0, 0)
	fmt.Println(One(f, 30000000))
}
