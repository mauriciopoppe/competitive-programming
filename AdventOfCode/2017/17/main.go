package main

import "fmt"

// One .
func One(n int) int {
	arr := make([]int, 1)
	cur := 0
	for i := 1; i <= 2017; i++ {
		prev := (cur + n) % len(arr)
		next := make([]int, 0)
		next = append(next, arr[0:prev+1]...)
		next = append(next, i)
		next = append(next, arr[prev+1:]...)
		cur = prev + 1
		arr = next
	}
	return arr[cur+1]
}

// Two .
func Two(n int) int {
	cur := 0
	zero := 0
	nextToZero := -1
	size := 1
	for i := 1; i <= int(50e6); i++ {
		next := (cur + n) % size
		if next == zero {
			nextToZero = i
		}
		cur = next + 1
		size++
	}
	return nextToZero
}

func main() {
	fmt.Println(One(355))
	fmt.Println(Two(355))
}
