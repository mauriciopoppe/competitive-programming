package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

func check(err error) {
	if err != nil {
		panic(err)
	}
}

func Loop(wanted int, subject int) int {
	n := 1
	loop := 0
	for n != wanted {
		n = (n * subject) % 20201227
		loop++

		//if loop == 100000 {
		//	panic("more than 10000 iterations!")
		//}
	}
	return loop
}

func Transform(subject int, loop int) int {
	n := 1
	for i := 0; i < loop; i++ {
		n = (n * subject) % 20201227
	}
	return n
}

// One solution
func One(r io.Reader) (int, int) {
	var err error
	scanner := bufio.NewScanner(r)
	scanner.Scan()
	card, err := strconv.Atoi(scanner.Text())
	check(err)
	scanner.Scan()
	door, err := strconv.Atoi(scanner.Text())
	check(err)

	cardLoop := Loop(card, 7)
	doorLoop := Loop(door, 7)

	cardEnc := Transform(card, doorLoop)
	doorEnc := Transform(door, cardLoop)

	return cardEnc, doorEnc
}

// Two solution
func Two(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	for scanner.Scan() {
	}
	return -1
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
