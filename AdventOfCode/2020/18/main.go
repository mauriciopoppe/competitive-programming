package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"unicode"
)

func check(err error) {
	if err != nil {
		panic(err)
	}
}

const (
	NUMBER = iota
	OPERATOR
	OPEN_PARENTHESIS
	CLOSE_PARENTHESIS
)

type Token struct {
	v   string
	typ int
	pre int
}

func Parse(expr string) []Token {
	out := make([]Token, 0)
	i := 0
	for i < len(expr) {
		for i < len(expr) && expr[i] == ' ' {
			i++
		}

		if i < len(expr) && unicode.IsDigit(rune(expr[i])) {
			n := 0
			for i < len(expr) && unicode.IsDigit(rune(expr[i])) {
				n = n*10 + int(expr[i]-'0')
				i++
			}
			out = append(out, Token{strconv.Itoa(n), NUMBER, 0})
			continue
		}

		if i < len(expr) {
			if expr[i] == '(' {
				out = append(out, Token{"(", OPEN_PARENTHESIS, 2})
			} else if expr[i] == ')' {
				out = append(out, Token{")", CLOSE_PARENTHESIS, 2})
			} else if expr[i] == '+' || expr[i] == '-' {
				out = append(out, Token{string(expr[i]), OPERATOR, 0})
			} else {
				out = append(out, Token{string(expr[i]), OPERATOR, 1})
			}
			i++
			continue
		}
	}
	return out
}

func Eval(q *[]int, op *[]Token) {
	if len(*q) < 2 {
		panic("less than 2 numbers")
	}

	if len(*op) < 1 {
		panic("less than 1 operator")
	}

	operator := (*op)[len(*op)-1]
	*op = (*op)[:len(*op)-1]

	b := (*q)[len(*q)-1]
	a := (*q)[len(*q)-2]
	*q = (*q)[:len(*q)-2]

	if operator.v == "+" {
		*q = append(*q, a+b)
	} else if operator.v == "-" {
		*q = append(*q, a-b)
	} else if operator.v == "*" {
		*q = append(*q, a*b)
	} else if operator.v == "/" {
		*q = append(*q, a/b)
	}
}

// One solution
func One(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	total := 0
	for scanner.Scan() {
		line := scanner.Text()
		tokens := Parse(line)

		q := make([]int, 0)
		op := make([]Token, 0)
		for _, t := range tokens {
			if t.typ == NUMBER {
				n, err := strconv.Atoi(t.v)
				check(err)
				q = append(q, n)
			}
			if t.typ == OPERATOR {
				for len(op) > 0 && op[len(op)-1].typ == OPERATOR {
					Eval(&q, &op)
				}
				op = append(op, t)
			}
			if t.typ == OPEN_PARENTHESIS {
				op = append(op, t)
			}
			if t.typ == CLOSE_PARENTHESIS {
				for len(op) > 0 && op[len(op)-1].typ != OPEN_PARENTHESIS {
					Eval(&q, &op)
				}
				op = op[:len(op)-1]
			}
		}
		for len(op) > 0 {
			Eval(&q, &op)
		}

		res := q[0]
		total += res
	}
	return total
}

// Two solution
func Two(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	total := 0
	for scanner.Scan() {
		line := scanner.Text()
		tokens := Parse(line)

		q := make([]int, 0)
		op := make([]Token, 0)
		for _, t := range tokens {
			if t.typ == NUMBER {
				n, err := strconv.Atoi(t.v)
				check(err)
				q = append(q, n)
			}
			if t.typ == OPERATOR {
				for len(op) > 0 && op[len(op)-1].typ == OPERATOR && op[len(op)-1].pre < t.pre {
					Eval(&q, &op)
				}
				op = append(op, t)
			}
			if t.typ == OPEN_PARENTHESIS {
				op = append(op, t)
			}
			if t.typ == CLOSE_PARENTHESIS {
				for len(op) > 0 && op[len(op)-1].typ != OPEN_PARENTHESIS {
					Eval(&q, &op)
				}
				op = op[:len(op)-1]
			}
		}
		for len(op) > 0 {
			Eval(&q, &op)
		}

		res := q[0]
		total += res
	}
	return total
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
