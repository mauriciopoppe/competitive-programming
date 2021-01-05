package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func check(err error) {
	if err != nil {
		panic(err)
	}
}

type Hex struct {
	x, y, z int
}

func (h *Hex) Add(v *Hex) *Hex {
	out := &Hex{h.x + v.x, h.y + v.y, h.z + v.z}
	return out
}

var d = make(map[string]*Hex)

func init() {
	d["w"] = &Hex{-1, 1, 0}
	d["sw"] = &Hex{-1, 0, 1}
	d["se"] = &Hex{0, -1, 1}
	d["e"] = &Hex{1, -1, 0}
	d["ne"] = &Hex{1, 0, -1}
	d["nw"] = &Hex{0, 1, -1}
}

// One solution
func One(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	black := make(map[Hex]bool)
	for scanner.Scan() {
		str := scanner.Text()

		i := 0
		hex := Hex{}
		for i < len(str) {
			for k, v := range d {
				if i+len(k) > len(str) {
					continue
				}
				tok := str[i : i+len(k)]
				if tok == k {
					hex = *(hex.Add(v))
					i += len(k)
					break
				}
			}
		}

		if _, ok := black[hex]; ok {
			delete(black, hex)
		} else {
			black[hex] = true
		}
	}

	return len(black)
}

// Two solution
func Two(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	black := make(map[Hex]bool)
	for scanner.Scan() {
		str := scanner.Text()

		i := 0
		hex := Hex{}
		for i < len(str) {
			for k, v := range d {
				if i+len(k) > len(str) {
					continue
				}
				tok := str[i : i+len(k)]
				if tok == k {
					hex = *(hex.Add(v))
					i += len(k)
					break
				}
			}
		}

		if _, ok := black[hex]; ok {
			delete(black, hex)
		} else {
			black[hex] = true
		}
	}

	L := 100
	for i := 0; i < L; i++ {
		blackNeighbors := make(map[Hex]int)
		for hex := range black {
			for _, diff := range d {
				next := *(hex.Add(diff))
				blackNeighbors[next]++
			}
		}

		nextBlack := make(map[Hex]bool)
		for blackNeighbor, cnt := range blackNeighbors {
			isBlack := black[blackNeighbor]
			if (isBlack && (cnt == 1 || cnt == 2)) || (!isBlack && cnt == 2) {
				nextBlack[blackNeighbor] = true
			}
		}

		black = nextBlack
	}

	return len(black)
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
