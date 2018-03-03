package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
	"strings"
)

func count(words []string) int {
	m := make(map[string]bool)
	for _, v := range words {
		if m[v] {
			return 0
		}
		m[v] = true
	}
	return 1
}

// One sol
func One(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanLines)
	valid := 0
	for scanner.Scan() {
		line := scanner.Text()
		words := strings.Fields(line)
		valid += count(words)
	}
	return valid
}

func sortString(w string) string {
	s := strings.Split(w, "")
	sort.Strings(s)
	return strings.Join(s, "")
}

func countDup(words []string) int {
	m := make(map[string]bool)
	for _, v := range words {
		v = sortString(v)
		if m[v] {
			return 0
		}
		m[v] = true
	}
	return 1
}

// Two sol
func Two(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanLines)
	valid := 0
	for scanner.Scan() {
		line := scanner.Text()
		words := strings.Fields(line)
		valid += countDup(words)
	}
	return valid
}

func main() {
	f, _ := os.Open("./in")

	f.Seek(0, 0)
	fmt.Println(One(f))

	f.Seek(0, 0)
	fmt.Println(Two(f))
}
