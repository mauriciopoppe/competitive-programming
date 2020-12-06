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
	mx := 0
	for scanner.Scan() {
		str := scanner.Text()
		var mid int
		lo := 0
		hi := 127
		for i := 0; i < 7; i++ {
			mid = lo + (hi-lo)/2
			if str[i] == 'F' {
				hi = mid
			} else {
				lo = mid + 1
			}
		}
		row := (lo + hi) / 2

		lo = 0
		hi = 7
		for i := 7; i < 10; i++ {
			mid = lo + (hi-lo)/2
			if str[i] == 'R' {
				lo = mid + 1
			} else {
				hi = mid
			}
		}

		col := (lo + hi) / 2
		//fmt.Println(row, col)

		t := row*8 + col
		if t > mx {
			mx = t
		}
	}
	return mx
}

// Two solution
func Two(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	mx := 0
	seen := make(map[int]int)
	line := 0
	for scanner.Scan() {
		str := scanner.Text()
		var mid int
		lo := 0
		hi := 127
		for i := 0; i < 7; i++ {
			mid = lo + (hi-lo)/2
			if str[i] == 'F' {
				hi = mid
			} else {
				lo = mid + 1
			}
		}
		row := lo

		lo = 0
		hi = 7
		for i := 7; i < 10; i++ {
			mid = lo + (hi-lo)/2
			if str[i] == 'R' {
				lo = mid + 1
			} else {
				hi = mid
			}
		}
		col := hi

		t := row*8 + col
		seen[t] = 1
		line++
	}

	mx = 0
	for i := 0; ; i++ {
		_, this := seen[i]
		_, prev := seen[i-1]
		_, next := seen[i+1]

		if !this && prev && next {
			mx = i
			break
		}
	}

	return mx
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
