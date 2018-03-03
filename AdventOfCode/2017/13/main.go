package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

// ParseOne .
func ParseOne(r io.Reader) []int {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanLines)
	ans := make([]int, 0)
	for scanner.Scan() {
		line := scanner.Text()
		var from, to int
		fmt.Sscanf(line, "%d: %d", &from, &to)
		for len(ans) <= from {
			ans = append(ans, 0)
		}
		ans[from] = to
	}
	return ans
}

// One .
func One(in []int) int {
	total := 0
	it := make([]int, len(in))
	inc := make([]int, len(in))
	for i := range inc {
		inc[i] = 1
	}
	for i := 0; i < len(it); i++ {
		// fmt.Println(it, i, it[i])
		if it[i] == 0 && in[i] > 0 {
			// fmt.Printf("Add %d\n", i)
			total += i * in[i]
		}
		for j := 0; j < len(it); j++ {
			if in[j] > 0 {
				it[j] = it[j] + inc[j]
				if it[j] == in[j]-1 {
					inc[j] = -1
				}
				if it[j] == 0 {
					inc[j] = 1
				}
			}
		}
	}
	return total
}

func t(size, step int) int {
	// size = 5
	// [0 1 2 3 4 5 6 7]
	// [0 1 2 3 4 3 2 1] size * 2 - 2
	// [-4 -3 -2 -1 0 1 2 3]
	period := size*2 - 2
	n := step % period
	if n >= size-1 {
		sub := n - (size - 1)
		n = size - sub
	}
	return n
}

// Two .
func Two(size []int) int {
	for steps := 0; ; steps++ {
		i := 0
		for ; i < len(size); i++ {
			if size[i] > 0 && t(size[i], steps+i) == 0 {
				// fmt.Printf("step %d, fail at %d\n", steps, i)
				break
			}
		}
		// fmt.Println(total)
		if i == len(size) {
			return steps
		}
	}
	return -1
}

func main() {
	f, _ := os.Open("./in")
	in := ParseOne(f)
	fmt.Println(One(in))
	fmt.Println(Two(in))
}
