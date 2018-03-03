# Advent of code

> Solving puzzles while learning a new language

## [2017](http://adventofcode.com/2017) - [Go](https://golang.org/)

Structure:

Three files: `in` (the input), `main.go` (the solution), `main_test.go` (the tests)

```sh
# computes the solutions
go run main.go
# unit tests
go test
```

Notes:

- input is read similar to Java with scanners
- the solution methods should receive the parsed input that way the method can be easily tested
- file should be rewinded after scanned if needed

Problems:

- No `abs`, `min`, `max` methods for `int`
- No direct conversion from `[]int` to `string`

Cheatsheet:

```go
// read a line with ? words
func parse(r io.Reader) []string {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanLines)
	scanner.Scan()
	line := scanner.Text()
	words := strings.Fields(line)
	return words
}

// read a list of integers separated by newline
func parse(r io.Reader) []int {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanLines)
	v := make([]int, 0)
	for scanner.Scan() {
		line := scanner.Text()
		n, _ := strconv.Atoi(line)
		v = append(v, n)
	}
	return v
}

// make a string reader compatible with io.Reader
func stor(s string) io.Reader {
	buf := make([]byte, len(s))
	io.ReadFull(strings.NewReader(s), buf)
	return bytes.NewReader(buf)
}
```

