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
	totalValid := 0
	for scanner.Scan() {
		var min, max int
		var ch int32
		var t string
		line := scanner.Text()
		_, _ = fmt.Sscanf(line, "%d-%d %c: %s", &min, &max, &ch, &t)
		fmt.Println(min, max, ch, t)
		current := 0
		for _, it := range t {
			if ch == it {
				current++
			}
		}
		if min <= current && current <= max {
			totalValid++
		}
	}
	return totalValid
}

// Two solution
func Two(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	totalValid := 0
	for scanner.Scan() {
		var min, max int
		var ch uint8
		var t string
		line := scanner.Text()
		fmt.Sscanf(line, "%d-%d %c: %s", &min, &max, &ch, &t)
		current := 0
		if t[min-1] == ch {
			current++
		}
		if t[max-1] == ch {
			current++
		}
		if current == 1 {
			totalValid++
		}
	}
	return totalValid
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
