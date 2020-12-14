package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strings"
)

func check(err error) {
	if err != nil {
		panic(err)
	}
}

// One solution
func One(r io.Reader) uint64 {
	scanner := bufio.NewScanner(r)
	mem := make(map[uint64]uint64)
	var mask string
	for scanner.Scan() {
		line := scanner.Text()
		if strings.HasPrefix(line, "mask") {
			_, err := fmt.Sscanf(line, "mask = %s", &mask)
			check(err)
		} else {
			var mempos, val uint64
			_, err := fmt.Sscanf(line, "mem[%d] = %d", &mempos, &val)
			check(err)

			var j uint64 = 0
			for i := len(mask) - 1; i >= 0; i-- {
				if mask[i] == '1' {
					val |= 1 << j
				} else if mask[i] == '0' {
					val &= ^(1 << j)
				}
				j++
			}
			mem[mempos] = val
		}
	}

	var sum uint64 = 0
	for _, v := range mem {
		sum += v
	}
	return sum
}

func dfs(M *[]uint64, mempos uint64, mask string, pos int, j int) {
	if pos == -1 {
		*M = append(*M, mempos)
	} else {
		if mask[pos] == '0' {
			dfs(M, mempos, mask, pos-1, j+1)
		} else if mask[pos] == '1' {
			mempos |= 1 << j
			dfs(M, mempos, mask, pos-1, j+1)
		} else {
			mempos |= 1 << j
			dfs(M, mempos, mask, pos-1, j+1)
			mempos &= ^(1 << j)
			dfs(M, mempos, mask, pos-1, j+1)
		}
	}
}

// Two solution
func Two(r io.Reader) uint64 {
	scanner := bufio.NewScanner(r)
	mem := make(map[uint64]uint64)
	var mask string
	for scanner.Scan() {
		line := scanner.Text()
		if strings.HasPrefix(line, "mask") {
			_, err := fmt.Sscanf(line, "mask = %s", &mask)
			check(err)
		} else {
			var mempos, val uint64
			_, err := fmt.Sscanf(line, "mem[%d] = %d", &mempos, &val)
			check(err)
			M := make([]uint64, 0)
			dfs(&M, mempos, mask, len(mask)-1, 0)
			for _, mempos = range M {
				mem[mempos] = val
			}
		}
	}

	var sum uint64 = 0
	for _, v := range mem {
		sum += v
	}
	return sum
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
