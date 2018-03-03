package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

type point struct {
	x int
	y int
	z int
}

type particle struct {
	p     point
	v     point
	a     point
	idx   int
	death bool
}

func parse(r io.Reader) []particle {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanLines)
	out := []particle{}
	i := 0
	for scanner.Scan() {
		line := scanner.Text()
		p := point{}
		v := point{}
		a := point{}
		fmt.Sscanf(line, "p=<%d,%d,%d>, v=<%d,%d,%d>, a=<%d,%d,%d>", &p.x, &p.y, &p.z, &v.x, &v.y, &v.z, &a.x, &a.y, &a.z)
		out = append(out, particle{p: p, v: v, a: a, idx: i, death: false})
		i++
	}
	return out
}

func abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}

func solve(p particle, ch chan int) {
	mn := int(1e9)
	for i := 0; i < int(1e6); i++ {
		// fmt.Println(p.idx, p.p)
		mn = abs(p.p.x) + abs(p.p.y) + abs(p.p.z)
		// if dist < mn {
		// 	mn = dist
		// }
		// 1st iter
		p.v.x += p.a.x
		p.v.y += p.a.y
		p.v.z += p.a.z
		// 2nd iter
		p.p.x += p.v.x
		p.p.y += p.v.y
		p.p.z += p.v.z
	}
	ch <- mn
}

// One .
func One(in []particle) int {
	var chans []chan int

	for i := range in {
		chans = append(chans, make(chan int))
		go solve(in[i], chans[i])
	}

	mn := int(1e9)
	idx := -1
	for i := range in {
		ans := <-chans[i]
		if ans < mn {
			idx = i
			mn = ans
		}
	}
	return idx
}

// Two .
func Two(particles []particle) int {
	for i := 0; i < int(1e2); i++ {
		crash := make(map[point]*particle)
		for j := range particles {
			p := &particles[j]
			if p.death {
				continue
			}
			old, ok := crash[p.p]
			if ok {
				(*old).death = true
				p.death = true
			}
			crash[p.p] = p
			// 1st
			p.v.x += p.a.x
			p.v.y += p.a.y
			p.v.z += p.a.z
			// 2nd
			p.p.x += p.v.x
			p.p.y += p.v.y
			p.p.z += p.v.z
		}
	}
	total := 0
	for _, p := range particles {
		if !p.death {
			total++
		}
	}
	return total
}

func main() {
	f, _ := os.Open("./in")
	defer f.Close()

	in := parse(f)
	fmt.Println(One(in))
	fmt.Println(Two(in))
}
