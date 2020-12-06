## Template

```go
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"regexp"
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
```
