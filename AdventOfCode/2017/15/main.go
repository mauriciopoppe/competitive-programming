package main

import (
	"fmt"
)

func cmp(a, b int64) int {
	for i := 0; i < 16; i++ {
		mask := int64(1 << uint(i))
		if a&mask != b&mask {
			return 0
		}
	}
	return 1
}

// MOD .
const MOD = 2147483647

// One .
func One(A, B int64) int {
	var a, b int64
	a = A
	b = B
	total := 0
	limit := int(40e6)
	for i := 0; i < limit; i++ {
		a *= 16807
		b *= 48271
		a %= MOD
		b %= MOD
		total += cmp(a, b)
	}
	return total
}

// Two .
func Two(A, B int64) int {
	var a, b int64
	a = A
	b = B
	total := 0
	limit := int(5e6)
	for i := 0; i < limit; i++ {
		for {
			a *= 16807
			a %= MOD
			if a%4 == 0 {
				break
			}
		}
		for {
			b *= 48271
			b %= MOD
			if b%8 == 0 {
				break
			}
		}
		total += cmp(a, b)
	}
	return total
}

func main() {
	fmt.Println(One(883, 879))
	fmt.Println(Two(883, 879))
}
