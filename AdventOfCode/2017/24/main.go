package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

type dom struct {
	l, r int
}

func (d *dom) flip() {
	t := d.l
	d.l = d.r
	d.r = t
}

func parse(r io.Reader) []dom {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanLines)
	out := make([]dom, 0)
	for scanner.Scan() {
		line := scanner.Text()
		d := dom{}
		fmt.Sscanf(line, "%d/%d", &d.l, &d.r)
		out = append(out, d)
	}
	return out
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func dfs(in []dom, visited []bool, n int, ac int, best *int) {
	// fmt.Println(visited)
	visited[n] = true
	ac += in[n].l + in[n].r
	*best = max(*best, ac)
	for i := range visited {
		if !visited[i] {
			if in[n].r == in[i].l {
				dfs(in, visited, i, ac, best)
			}
			if in[n].r == in[i].r {
				in[i].flip()
				dfs(in, visited, i, ac, best)
			}
		}
	}
	visited[n] = false
}

// One .
func One(in []dom) int {
	visited := make([]bool, len(in))
	best := 0
	for i := range in {
		if in[i].l == 0 || in[i].r == 0 {
			if in[i].r == 0 {
				in[i].flip()
			}
			dfs(in, visited, i, 0, &best)
		}
	}
	return best
}

func dfs2(in []dom, visited []bool, n int, ac int, depth int, best *int, longest *int) {
	visited[n] = true
	depth++
	ac += in[n].l + in[n].r
	if depth > *longest {
		*best = ac
		*longest = depth
	} else if depth == *longest && ac > *best {
		*best = ac
	}
	for i := range visited {
		if !visited[i] {
			if in[n].r == in[i].l {
				dfs2(in, visited, i, ac, depth, best, longest)
			}
			if in[n].r == in[i].r {
				in[i].flip()
				dfs2(in, visited, i, ac, depth, best, longest)
			}
		}
	}
	visited[n] = false
}

// Two .
func Two(in []dom) int {
	visited := make([]bool, len(in))
	longest := 0
	best := 0
	for i := range in {
		if in[i].l == 0 || in[i].r == 0 {
			if in[i].r == 0 {
				in[i].flip()
			}
			dfs2(in, visited, i, 0, 0, &best, &longest)
		}
	}
	return best
}

func main() {
	f, _ := os.Open("./in")
	defer f.Close()

	in := parse(f)
	fmt.Println(One(in))
	fmt.Println(Two(in))
}
