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

// Template is the template for the problems
func Template(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	for scanner.Scan() {
	}
	return -1
}

func Index(slice []string, item string) int {
	for i, _ := range slice {
		if slice[i] == item {
			return i
		}
	}
	return -1
}

// Template is the template for the problems
func One(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	total := 0
	for {
		allTokens := make([]string, 0)
		var line string
		for scanner.Scan() {
			line = scanner.Text()
			if len(line) == 0 {
				break
			}
			tokens := strings.Split(line, " ")
			allTokens = append(allTokens, tokens...)
		}

		if len(allTokens) == 0 {
			break
		}

		required := []string{"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"}
		cnt := 0
		for _, token := range allTokens {
			kv := strings.Split(token, ":")
			if Index(required, kv[0]) > -1 {
				cnt++
			}
		}
		if cnt == len(required) {
			total++
		}
	}
	return total
}

// Two solution
func Two(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	total := 0
	for {
		allTokens := make([]string, 0)
		var line string
		for scanner.Scan() {
			line = scanner.Text()
			if len(line) == 0 {
				break
			}
			tokens := strings.Split(line, " ")
			allTokens = append(allTokens, tokens...)
		}

		if len(allTokens) == 0 {
			break
		}

		cnt := 0
		for _, token := range allTokens {
			kv := strings.Split(token, ":")
			if kv[0] == "byr" {
				t, err := strconv.Atoi(kv[1])
				if err != nil {
					continue
				}
				if 1920 <= t && t <= 2002 {
					cnt++
				}
			}

			if kv[0] == "iyr" {
				t, err := strconv.Atoi(kv[1])
				if err != nil {
					panic(err)
				}
				if 2010 <= t && t <= 2020 {
					cnt++
				}
			}

			if kv[0] == "eyr" {
				t, err := strconv.Atoi(kv[1])
				if err != nil {
					panic(err)
				}
				if 2020 <= t && t <= 2030 {
					cnt++
				}
			}

			if kv[0] == "hgt" {
				var typ string
				var n int
				_, err := fmt.Sscanf(kv[1], "%d%s", &n, &typ)
				if err != nil {
					//panic(err)
					continue
				}

				if typ == "cm" && 150 <= n && n <= 193 {
					cnt++
				}
				if typ == "in" && 59 <= n && n <= 76 {
					cnt++
				}
			}

			if kv[0] == "hcl" {
				valid := regexp.MustCompile(`#[a-f0-9]{6}`)
				if valid.MatchString(kv[1]) {
					cnt++
				}
			}

			if kv[0] == "ecl" {
				valid := regexp.MustCompile(`amb|blu|brn|gry|grn|hzl|oth`)
				if valid.MatchString(kv[1]) {
					cnt++
				}
			}

			if kv[0] == "pid" {
				valid := regexp.MustCompile(`^[0-9]{9}$`)
				if valid.MatchString(kv[1]) {
					cnt++
				}
			}
		}
		if cnt == 7 {
			total++
		}
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
