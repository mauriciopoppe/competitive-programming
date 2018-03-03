package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
	"strings"
)

// ParseOne .
func ParseOne(r io.Reader) []string {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanLines)
	for scanner.Scan() {
		line := scanner.Text()
		return strings.Split(line, ",")
	}
	return nil
}

type coord struct {
	X, Y, Z int
}

func (c coord) Add(o coord) coord {
	return coord{
		c.X + o.X,
		c.Y + o.Y,
		c.Z + o.Z,
	}
}

// Abs .
func Abs(v int) int {
	if v < 0 {
		return -v
	}
	return v
}

// One .
func One(s []string) int {
	m := make(map[string]coord)
	m["n"] = coord{0, 1, -1}
	m["s"] = coord{0, -1, 1}
	m["ne"] = coord{1, 0, -1}
	m["se"] = coord{1, -1, 0}
	m["nw"] = coord{-1, 1, 0}
	m["sw"] = coord{-1, 0, 1}
	o := coord{0, 0, 0}
	for i := range s {
		o = o.Add(m[s[i]])
	}
	fmt.Println(o)
	total := (Abs(o.X) + Abs(o.Y) + Abs(o.Z)) / 2
	return total
}

// Two .
func Two(s []string) int {
	m := make(map[string]coord)
	m["n"] = coord{0, 1, -1}
	m["s"] = coord{0, -1, 1}
	m["ne"] = coord{1, 0, -1}
	m["se"] = coord{1, -1, 0}
	m["nw"] = coord{-1, 1, 0}
	m["sw"] = coord{-1, 0, 1}
	o := coord{0, 0, 0}
	mx := 0.
	for i := range s {
		o = o.Add(m[s[i]])
		total := (Abs(o.X) + Abs(o.Y) + Abs(o.Z)) / 2
		mx = math.Max(mx, float64(total))
	}
	return int(mx)
}

func main() {
	f, _ := os.Open("./in")
	in := ParseOne(f)
	fmt.Println(One(in))
	fmt.Println(Two(in))
}
