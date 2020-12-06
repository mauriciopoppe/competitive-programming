package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

// Template is the template for the problems
func One(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	var total = 0
	for {
		char := make(map[rune]bool)
		for scanner.Scan() {
			str := scanner.Text()
			if len(str) == 0 {
				break
			}
			for _, ch := range str {
				char[ch] = true
			}
		}
		if len(char) == 0 {
			break
		}
		total += len(char)
	}
	return total

}

// Two solution
func Two(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	var total = 0
	for {
		lines := make([]string, 0)
		cnt := make([]int, 128)
		for scanner.Scan() {
			str := scanner.Text()
			if len(str) == 0 {
				break
			}

			for _, ch := range str {
				cnt[ch]++
			}
			lines = append(lines, str)
		}
		if len(lines) == 0 {
			break
		}
		for k := 'a'; k <= 'z'; k++ {
			if cnt[k] == len(lines) {
				total++
			}
		}
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
