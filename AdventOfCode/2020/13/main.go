package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func check(err error) {
	if err != nil {
		panic(err)
	}
}

// One solution
func One(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	ans := -1
	best := int(1e9)
	for scanner.Scan() {
		early, err := strconv.Atoi(scanner.Text())
		check(err)

		scanner.Scan()
		buses := strings.Split(scanner.Text(), ",")

		for _, strv := range buses {
			if strv == "x" {
				continue
			}

			v, err := strconv.Atoi(strv)
			check(err)

			k := early / v
			k *= v
			if v < early {
				k += v
			}

			if k-early < best {
				best = k - early
				ans = (k - early) * v
			}
		}
	}
	return ans
}

type GCD struct {
	x, y, d int64
}

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func LCM(a, b int64) int64 {
	return a / gcd(a, b) * b
}

func norm(x, mod int64) int64 {
	x %= mod
	if x < 0 {
		x += mod
	}
	return x
}

func extGCD(a, b int64) GCD {
	if b == 0 {
		return GCD{1, 0, a}
	}
	pom := extGCD(b, a%b)
	return GCD{pom.y, pom.x - a/b*pom.y, pom.d}
}

func chineseRemainder(A, P []int64) int64 {
	var ans = A[0]
	var lcm = P[0]

	for i := 1; i < len(A); i++ {
		var pom = extGCD(lcm, P[i])
		x1 := pom.x
		d := pom.d
		if (A[i]-ans)%d != 0 {
			panic("no solutions")
		}
		ans = norm(ans+x1*(A[i]-ans)/d%(P[i]/d)*lcm, lcm*P[i]/d)
		lcm = LCM(lcm, P[i])
	}
	return ans
}

// Two solution
func Two(r io.Reader) int64 {
	scanner := bufio.NewScanner(r)

	A := make([]int64, 0)
	P := make([]int64, 0)
	scanner.Scan()
	_, err := strconv.Atoi(scanner.Text())
	check(err)

	scanner.Scan()
	buses := strings.Split(scanner.Text(), ",")

	for i, strv := range buses {
		if strv == "x" {
			continue
		}

		v, err := strconv.Atoi(strv)
		check(err)
		P = append(P, int64(v))
		A = append(A, int64(v-i))
	}
	A[0] = 0
	//fmt.Println("A", A)
	//fmt.Println("P", P)

	out := chineseRemainder(A, P)
	return out
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
