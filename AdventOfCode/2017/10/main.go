package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

// ParseOne .
func ParseOne(r io.Reader) []int {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanLines)
	scanner.Scan()
	line := scanner.Text()
	ans := make([]int, 0)
	for _, v := range strings.Split(line, ",") {
		n, _ := strconv.Atoi(v)
		ans = append(ans, n)
	}
	return ans
}

// ParseTwo .
func ParseTwo(r io.Reader) []int {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanLines)
	scanner.Scan()
	line := scanner.Text()
	byteArray := []byte(line)
	ans := make([]int, 0)
	for _, v := range byteArray {
		ans = append(ans, int(v))
	}
	ans = append(ans, 17, 31, 73, 47, 23)
	return ans
}

func reverse(v []int, i int, j int) {
	var n int
	n = (j - i + 1) / 2
	if i > j {
		n = (j + len(v) - i + 1) / 2
	}
	for n > 0 {
		t := v[i]
		v[i] = v[j]
		v[j] = t
		i = (i + 1) % len(v)
		j = ((j - 1) + len(v)) % len(v)
		n--
	}
}

// One .
func One(size int, in []int) int {
	v := make([]int, size)
	for i := range v {
		v[i] = i
	}
	skip := 0
	pos := 0
	for i := range in {
		if in[i] > len(v) {
			continue
		}
		from := pos
		to := (pos + in[i] - 1) % len(v)
		if in[i] > 0 {
			reverse(v, from, to)
		}
		pos = (pos + in[i] + skip) % len(v)
		skip++
	}
	return v[0] * v[1]
}

// Two .
func Two(size int, in []int) string {
	v := make([]int, size)
	for i := range v {
		v[i] = i
	}
	skip := 0
	pos := 0
	for j := 0; j < 64; j++ {
		for i := range in {
			from := pos
			to := (pos + in[i] - 1) % len(v)
			if in[i] > 0 {
				reverse(v, from, to)
			}
			pos = (pos + in[i] + skip) % len(v)
			skip++
		}
	}
	xor := make([]string, 0)
	for j := 0; j < 16; j++ {
		var partial int64
		partial = 0
		for i := 0; i < 16; i++ {
			partial ^= int64(v[j*16+i])
		}
		xor = append(xor, fmt.Sprintf("%02x", partial))
	}
	return strings.Join(xor[:], "")
}

func main() {
	f, _ := os.Open("./in")
	var ins []int
	ins = ParseOne(f)
	fmt.Println(One(256, ins))

	f.Seek(0, 0)
	ins = ParseTwo(f)
	fmt.Println(Two(256, ins))
}
