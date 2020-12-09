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

// One solution
func One(r io.Reader) int64 {
	scanner := bufio.NewScanner(r)
	numbers := make([]int64, 0)
	for scanner.Scan() {
		n, _ := strconv.ParseInt(scanner.Text(), 10, 0)
		numbers = append(numbers, n)
	}

	for iter := 25; iter < len(numbers); iter += 1 {
		found := false
		for i := iter - 25; i < iter; i++ {
			for j := i + 1; j < iter; j++ {
				if numbers[i]+numbers[j] == numbers[iter] {
					found = true
				}
			}
		}
		if !found {
			return numbers[iter]
		}
	}

	return -1
}

// Two solution
func Two(r io.Reader) int64 {
	scanner := bufio.NewScanner(r)
	numbers := make([]int64, 0)
	for scanner.Scan() {
		n, _ := strconv.ParseInt(scanner.Text(), 10, 0)
		numbers = append(numbers, n)
	}

	var target int64
	for iter := 25; iter < len(numbers); iter += 1 {
		found := false
		for i := iter - 25; i < iter; i++ {
			for j := i + 1; j < iter; j++ {
				if numbers[i]+numbers[j] == numbers[iter] {
					found = true
				}
			}
		}
		if !found {
			target = numbers[iter]
			break
		}
	}

	for i := 0; i < len(numbers); i++ {
		var sum int64
		var min, max int64
		min = int64(1e18)
		max = 0
		sum = 0
		for j := i; j < len(numbers); j++ {
			sum += numbers[j]
			if numbers[j] < min {
				min = numbers[j]
			}
			if numbers[j] > max {
				max = numbers[j]
			}
			if sum == target {
				return min + max
			}
			if sum > target {
				break
			}
		}
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
