package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
	"strconv"
	"strings"
)

// One sol
func One(r io.Reader) float64 {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanLines)
	total := 0.
	for scanner.Scan() {
		line := scanner.Text()
		tokens := strings.Fields(line)
		var min, max float64
		min = 1e10
		max = -1e10
		for _, n := range tokens {
			nf, _ := strconv.ParseFloat(n, 64)
			min = math.Min(min, nf)
			max = math.Max(max, nf)
		}
		total += max - min
	}
	return total
}

// Two sol
func Two(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanLines)
	total := 0
	for scanner.Scan() {
		line := scanner.Text()
		tokens := strings.Fields(line)
		ints := make([]int, len(tokens))
		for i, s := range tokens {
			ints[i], _ = strconv.Atoi(s)
		}
		var div int
		for i := range tokens {
			for j := range tokens {
				if i != j && ints[i]%ints[j] == 0 {
					div = ints[i] / ints[j]
				}
			}
		}
		total += div
	}
	return total
}

func main() {
	f, _ := os.Open("./in")
	defer f.Close()

	f.Seek(0, 0)
	fmt.Println(One(f))

	f.Seek(0, 0)
	fmt.Println(Two(f))
}
