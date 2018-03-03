package main

import (
	"fmt"
	"strings"
)

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

func hash(line string) string {
	byteArray := []byte(line)
	in := make([]int, 0)
	for _, v := range byteArray {
		in = append(in, int(v))
	}
	in = append(in, 17, 31, 73, 47, 23)
	size := 256

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

func bits(c string, i int) int {
	var n int
	n = int(c[i] - '0')
	if c[i] >= 'a' {
		n = int(c[i] - 'a' + 10)
	}
	total := 0
	for n > 0 {
		if n&1 > 0 {
			total++
		}
		n /= 2
	}
	return total
}

// One .
func One(in string) int {
	total := 0
	for i := 0; i < 128; i++ {
		str := fmt.Sprintf("%s-%d", in, i)
		strh := hash(str)
		for i := range strh {
			total += bits(strh, i)
		}
	}
	return total
}

// Matrix .
type Matrix struct {
	data [][]int
}

func (m Matrix) init() Matrix {
	m.data = make([][]int, 128)
	for i := 0; i < 128; i++ {
		row := make([]int, 128)
		m.data[i] = row
	}
	return m
}

func (m Matrix) set(s string, i int, j int) {
	var n int
	n = int(s[j] - '0')
	if s[j] >= 'a' {
		n = int(s[j] - 'a' + 10)
	}
	t := 3
	// a: 1010
	for n > 0 {
		m.data[i][j*4+t] = n % 2
		t--
		n /= 2
	}
}

func (m Matrix) dfs(i, j int) {
	if i >= 0 && i < 128 && j >= 0 && j < 128 && m.data[i][j] > 0 {
		m.data[i][j] = 0
		m.dfs(i-1, j)
		m.dfs(i+1, j)
		m.dfs(i, j-1)
		m.dfs(i, j+1)
	}
}

// Add .
func (m Matrix) Add(s string, i int) {
	for j := range s {
		m.set(s, i, j)
	}
}

// Two .
func Two(in string) int {
	m := Matrix{}
	m = m.init()
	for i := 0; i < 128; i++ {
		str := fmt.Sprintf("%s-%d", in, i)
		str = hash(str)
		m.Add(str, i)
	}
	total := 0
	for i := 0; i < 128; i++ {
		for j := 0; j < 128; j++ {
			if m.data[i][j] > 0 {
				m.dfs(i, j)
				total++
			}
		}
	}
	return total
}

func main() {
	in := "nbysizxe"
	fmt.Println(One(in))
	fmt.Println(Two(in))
}
