package main

import "fmt"

// State .
type State struct {
	inst map[int][]int
}

// One .
func One(states map[int]State, iter int) int {
	total := 0
	val := make(map[int]int)
	pos := 0
	state := states[int('A')]

	for i := 0; i < iter; i++ {
		inst := state.inst[val[pos]]
		// fmt.Println(inst, val[pos])
		// fmt.Println(val)
		val[pos] = inst[0]
		pos += inst[1]
		state = states[inst[2]]
	}

	for _, v := range val {
		if v > 0 {
			total++
		}
	}

	return total
}

func getInput() map[int]State {
	states := make(map[int]State)

	var st map[int][]int

	// "A"
	st = map[int][]int{
		0: []int{1, 1, int('B')},
		1: []int{0, 1, int('F')},
	}
	states[int('A')] = State{st}

	// "B"
	st = map[int][]int{
		0: []int{0, -1, int('B')},
		1: []int{1, -1, int('C')},
	}
	states[int('B')] = State{st}

	st = map[int][]int{
		0: []int{1, -1, int('D')},
		1: []int{0, 1, int('C')},
	}
	states[int('C')] = State{st}

	st = map[int][]int{
		0: []int{1, -1, int('E')},
		1: []int{1, 1, int('A')},
	}
	states[int('D')] = State{st}

	st = map[int][]int{
		0: []int{1, -1, int('F')},
		1: []int{0, -1, int('D')},
	}
	states[int('E')] = State{st}

	st = map[int][]int{
		0: []int{1, 1, int('A')},
		1: []int{0, -1, int('E')},
	}
	states[int('F')] = State{st}

	return states
}

func getSampleInput() map[int]State {
	states := make(map[int]State)

	var st map[int][]int

	// "A"
	st = map[int][]int{
		0: []int{1, 1, int('B')},
		1: []int{0, -1, int('B')},
	}
	states[int('A')] = State{st}

	// "B"
	st = map[int][]int{
		0: []int{1, -1, int('A')},
		1: []int{1, 1, int('A')},
	}
	states[int('B')] = State{st}

	return states
}

func main() {
	// fmt.Println(One(getSampleInput(), 6))
	fmt.Println(One(getInput(), 12425180))
}
