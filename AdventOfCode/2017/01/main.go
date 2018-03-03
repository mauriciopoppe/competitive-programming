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
	scanner.Split(bufio.ScanLines)
	total := 0
	for scanner.Scan() {
		data := scanner.Text()
		for i := range data {
			if i > 0 {
				if data[i] == data[i-1] {
					total += int(data[i] - '0')
				}
			}
		}
		if data[0] == data[len(data)-1] {
			total += int(data[0] - '0')
		}
	}
	return total
}

// Two solution
func Two(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanLines)
	total := 0
	for scanner.Scan() {
		data := scanner.Text()
		n := len(data) / 2
		for i := range data {
			next := (i + n) % len(data)
			if data[i] == data[next] {
				total += int(data[i] - '0')
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
