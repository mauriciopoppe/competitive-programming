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

func Shift(A []int, n int) []int {
	if n < 0 {
		n = n + len(A)
	}
	n = n % len(A)

	out := make([]int, len(A))
	copy(out[:n], A[len(A)-n:])
	copy(out[n:], A[:len(A)-n])
	return out
}

func Find(A []int, n int) int {
	for k, v := range A {
		if v == n {
			return k
		}
	}
	return -1
}

// One solution
func One(r io.Reader) string {
	scanner := bufio.NewScanner(r)
	scanner.Scan()
	str := scanner.Text()

	A := make([]int, 0)
	for _, char := range str {
		A = append(A, int(char-'0'))
	}
	L := len(A)

	// curIndex is an array index
	curIndex := 0
	for round := 0; round < 100; round++ {
		curr := A[curIndex]
		A = Shift(A, L-(curIndex+4))
		left := A[:L-3]
		right := A[L-3:]

		// find the position to insert right
		nextIndex := -1
		wanted := curr
		for nextIndex == -1 {
			wanted--
			if wanted < 1 {
				wanted += L
			}

			nextIndex = Find(left, wanted)
		}
		//fmt.Println(nextIndex)

		nextA := make([]int, 0)
		nextA = append(nextA, left[:nextIndex+1]...)
		nextA = append(nextA, right...)
		nextA = append(nextA, left[nextIndex+1:]...)

		//fmt.Println("NextOut", nextA)

		for k, v := range nextA {
			if v == curr {
				curIndex = (k + 1) % L
			}
		}

		A = nextA
	}

	nextIndex := Find(A, 1)
	prepareOut := make([]int, 0)
	prepareOut = append(prepareOut, A[nextIndex+1:]...)
	prepareOut = append(prepareOut, A[:nextIndex]...)

	//fmt.Println(A, prepareOut)

	out := make([]string, 0)
	for _, v := range prepareOut {
		out = append(out, strconv.Itoa(v))
	}

	return strings.Join(out, "")
}

type Node struct {
	val  int
	next *Node
}

// Two solution
func Two(r io.Reader) int64 {
	scanner := bufio.NewScanner(r)
	scanner.Scan()
	str := scanner.Text()

	L := 1_000_000
	nodes := make(map[int]*Node)
	for i := 1; i <= L; i++ {
		nodes[i] = &Node{i, nil}
	}
	for i := 1; i < len(str); i++ {
		cur := int(str[i-1] - '0')
		nxt := int(str[i] - '0')
		nodes[cur].next = nodes[nxt]
	}
	for i := 11; i <= L; i++ {
		nodes[i-1].next = nodes[i]
	}
	if L > 9 {
		nodes[int(str[len(str)-1]-'0')].next = nodes[10]
		nodes[L].next = nodes[int(str[0]-'0')]
	} else {
		nodes[int(str[len(str)-1]-'0')].next = nodes[int(str[0]-'0')]
	}

	head := nodes[int(str[0]-'0')]
	for round := 0; round < 10_000_000; round++ {
		three := []*Node{head.next, head.next.next, head.next.next.next}
		threeStart := three[0]
		threeEnd := three[len(three)-1]

		wanted := head.val
		for {
			wanted--
			if wanted == 0 {
				wanted = L
			}

			found := false
			for _, node := range three {
				if node.val == wanted {
					found = true
				}
			}
			if !found {
				break
			}
		}

		head.next = threeEnd.next

		dest := nodes[wanted]
		threeEnd.next = dest.next
		dest.next = threeStart
		head = head.next
	}

	a := int64(nodes[1].next.val)
	b := int64(nodes[1].next.next.val)
	return a * b
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
