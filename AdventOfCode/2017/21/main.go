package main

import (
	"bufio"
	"bytes"
	"fmt"
	"io"
	"os"
	"strings"
)

func parse(r io.Reader) map[string]string {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanLines)
	out := make(map[string]string)
	for scanner.Scan() {
		line := scanner.Text()
		var from, to string
		fmt.Sscanf(line, "%s => %s", &from, &to)
		out[from] = to
	}
	return out
}

type matrix struct {
	inline   string
	expanded [][]byte
	size     int
	div      int
	two      bool
	three    bool
}

func newMatrix(inline string) *matrix {
	m := new(matrix)
	m.inline = inline
	m.size = strings.Index(inline, "/")
	if m.size%2 == 0 {
		m.div = 2
	} else {
		m.div = 3
	}
	buf := make([]byte, 0)
	for i := range inline {
		if inline[i] == '/' {
			m.expanded = append(m.expanded, buf)
			buf = make([]byte, 0)
		} else {
			buf = append(buf, inline[i])
		}
	}
	m.expanded = append(m.expanded, buf)
	return m
}

func (m *matrix) getSub(x, y int) string {
	var buffer bytes.Buffer
	for i := x; i < x+m.div; i++ {
		for j := y; j < y+m.div; j++ {
			buffer.WriteByte(m.expanded[i][j])
		}
		if i < x+m.div-1 {
			buffer.WriteString("/")
		}
	}
	return buffer.String()
}

func (m *matrix) next(in map[string]string, cache map[string]string) *matrix {
	var nextChunkSize int
	if m.div == 3 {
		nextChunkSize = 4
	} else {
		nextChunkSize = 3
	}
	totalSize := nextChunkSize * m.size / m.div
	nextMatrix := make([][]byte, 0)
	for i := 0; i < totalSize; i++ {
		nextMatrix = append(nextMatrix, make([]byte, totalSize))
	}

	// fmt.Println(m.size, totalSize)

	for i := 0; i < m.size/m.div; i++ {
		for j := 0; j < m.size/m.div; j++ {
			// fmt.Printf("total %d/%d\n", i*m.size/m.div+j, m.size*m.size/m.div/m.div)
			nx := i * m.div
			ny := j * m.div
			var cur *matrix
			cur = newMatrix(m.getSub(nx, ny))
			cur = newMatrix(rotateAndMatch(cur, in, cache))
			for ni := 0; ni < nextChunkSize; ni++ {
				for nj := 0; nj < nextChunkSize; nj++ {
					nextMatrix[i*nextChunkSize+ni][j*nextChunkSize+nj] = cur.expanded[ni][nj]
				}
			}
		}
	}

	var buffer bytes.Buffer
	for i := 0; i < totalSize; i++ {
		buffer.Write(nextMatrix[i])
		if i < totalSize-1 {
			buffer.WriteString("/")
		}
	}

	return newMatrix(buffer.String())
}

func (m *matrix) rotate() *matrix {
	var inline string
	for j := 0; j < m.size; j++ {
		for i := m.size - 1; i >= 0; i-- {
			inline += string(m.expanded[i][j])
		}
		if j < m.size-1 {
			inline += "/"
		}
	}
	return newMatrix(inline)
}

func (m *matrix) flipH() *matrix {
	var inline string
	for i := m.size - 1; i >= 0; i-- {
		for j := 0; j < m.size; j++ {
			inline += string(m.expanded[i][j])
		}
		if i > 0 {
			inline += "/"
		}
	}
	return newMatrix(inline)
}

func (m *matrix) flipV() *matrix {
	var inline string
	for i := 0; i < m.size; i++ {
		for j := m.size - 1; j >= 0; j-- {
			inline += string(m.expanded[i][j])
		}
		if i < m.size-1 {
			inline += "/"
		}
	}
	return newMatrix(inline)
}

func rotateAndMatch(m *matrix, in map[string]string, cache map[string]string) string {
	next := m
	if at, ok := cache[m.inline]; ok {
		return at
	}
	var ans string
	for i := 0; i < 4; i++ {
		next = next.rotate()
		if at, ok := in[next.inline]; ok {
			ans = at
			break
		}
		next = next.flipH()
		if at, ok := in[next.inline]; ok {
			ans = at
			break
		}
		next = next.flipH()
		next = next.flipV()
		if at, ok := in[next.inline]; ok {
			ans = at
			break
		}
		next = next.flipV()
	}
	cache[m.inline] = ans
	return ans
}

// One .
func One(in map[string]string, iter int) int {
	n := newMatrix(".#./..#/###")
	cache := make(map[string]string)

	for z := 0; z < iter; z++ {
		n = n.next(in, cache)
	}

	total := 0
	for _, ch := range n.inline {
		if ch == '#' {
			total++
		}
	}
	return total
}

func main() {
	f, _ := os.Open("./in")
	defer f.Close()

	in := parse(f)
	fmt.Println(One(in, 5))
	fmt.Println(One(in, 18))
}
