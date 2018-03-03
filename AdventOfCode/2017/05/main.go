package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

// One sol
func One(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanLines)
	v := make([]int, 0)
	for scanner.Scan() {
		line := scanner.Text()
		n, _ := strconv.Atoi(line)
		v = append(v, n)
	}
	total := 0
	pos := 0
	for {
		if pos < 0 || pos >= len(v) {
			return total
		}
		oldpos := pos
		pos += v[pos]
		v[oldpos]++
		total++
	}
}

func abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}

// Two sol
func Two(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanLines)
	v := make([]int, 0)
	for scanner.Scan() {
		line := scanner.Text()
		n, _ := strconv.Atoi(line)
		v = append(v, n)
	}
	total := 0
	pos := 0
	for {
		if pos < 0 || pos >= len(v) {
			return total
		}
		oldpos := pos
		offset := v[pos]
		pos += v[pos]
		if offset >= 3 {
			v[oldpos]--
		} else {
			v[oldpos]++
		}
		total++
	}
}

func main() {
	f, _ := os.Open("./in")

	f.Seek(0, 0)
	fmt.Println(One(f))

	f.Seek(0, 0)
	fmt.Println(Two(f))
}
