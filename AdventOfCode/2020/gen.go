package main

import (
	"io/ioutil"
	"os"
)

const mainGo = `
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

// One solution
func One(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	for scanner.Scan() {
        // scanner.Text()
	}
	return -1
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
`

const mainTestGo = `
package main

import (
	"io"
	"strings"
	"testing"
)

func TestOne(t *testing.T) {
	type args struct {
		r io.Reader
	}

	r := strings.NewReader(strings.TrimSpace(` + "``" + `))

	tests := []struct {
		name string
		args args
		want int
	}{
		{"One", args{r}, -1},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := One(tt.args.r); got != tt.want {
				t.Errorf("One() = %v, want %v", got, tt.want)
			}
		})
	}
}

func TestTwo(t *testing.T) {
	type args struct {
		r io.Reader
	}

	r := strings.NewReader(strings.TrimSpace(` + "``" + `))

	tests := []struct {
		name string
		args args
		want int
	}{
		{"Two", args{r}, -1},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := Two(tt.args.r); got != tt.want {
				t.Errorf("Two() = %v, want %v", got, tt.want)
			}
		})
	}
}
`

func main() {
	n := os.Args[1]
	err := os.MkdirAll(n, os.ModePerm)
	if err != nil {
		panic(err)
	}

	err = ioutil.WriteFile(n+"/main.go", []byte(mainGo), 0644)
	if err != nil {
		panic(err)
	}

	err = ioutil.WriteFile(n+"/main_test.go", []byte(mainTestGo), 0644)
	if err != nil {
		panic(err)
	}

	err = ioutil.WriteFile(n+"/in", []byte(""), 0644)
	if err != nil {
		panic(err)
	}
}
