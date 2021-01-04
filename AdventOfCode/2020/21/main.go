package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
	"strings"
)

func check(err error) {
	if err != nil {
		panic(err)
	}
}

type Food struct {
	ingredients map[string]bool
	allergens   map[string]bool
}

func NewFood() *Food {
	return &Food{
		ingredients: map[string]bool{},
		allergens:   map[string]bool{},
	}
}

func findFood(foods []Food, allergen string, ingredient string) bool {
	for i := 0; i < len(foods); i += 1 {
		food := foods[len(foods)-i-1]
		if food.allergens[allergen] {
			if !food.ingredients[ingredient] {
				return false
			}
		}
	}
	return true
}

// One solution
func One(r io.Reader) int {
	scanner := bufio.NewScanner(r)
	foods := make([]Food, 0)
	for scanner.Scan() {
		line := scanner.Text()
		line = line[:len(line)-1]
		toks := strings.Split(line, " (contains ")
		if len(toks) != 2 {
			panic("wanted 2")
		}

		ingredients := strings.Split(toks[0], " ")
		allergens := strings.Split(toks[1], ", ")
		f := NewFood()
		for _, v := range ingredients {
			f.ingredients[v] = true
		}
		for _, v := range allergens {
			f.allergens[v] = true
		}
		foods = append(foods, *f)
	}

	valid := map[string]bool{}
	for _, food := range foods {
		for allergen := range food.allergens {
			for ingredient := range food.ingredients {
				if findFood(foods, allergen, ingredient) {
					valid[ingredient] = true
				}
			}
		}
	}

	total := 0
	for _, food := range foods {
		for ingredient := range food.ingredients {
			if !valid[ingredient] {
				total++
			}
		}
	}

	return total
}

// Two solution
func Two(r io.Reader) string {
	scanner := bufio.NewScanner(r)
	foods := make([]Food, 0)
	for scanner.Scan() {
		line := scanner.Text()
		line = line[:len(line)-1]
		toks := strings.Split(line, " (contains ")
		if len(toks) != 2 {
			panic("wanted 2")
		}

		ingredients := strings.Split(toks[0], " ")
		allergens := strings.Split(toks[1], ", ")
		f := NewFood()
		for _, v := range ingredients {
			f.ingredients[v] = true
		}
		for _, v := range allergens {
			f.allergens[v] = true
		}
		foods = append(foods, *f)
	}

	type Pair struct {
		allergen, ingredient string
	}
	allergenToIngredients := make(map[string][]string)
	for _, food := range foods {
		for allergen := range food.allergens {
			for ingredient := range food.ingredients {
				if findFood(foods, allergen, ingredient) {
					Add(allergenToIngredients, allergen, ingredient)
				}
			}
		}
	}

	allergens := make([]string, 0)
	for allergen := range allergenToIngredients {
		allergens = append(allergens, allergen)
	}
	sort.Strings(allergens)

	var dfs func(iter int)

	var out string
	chosen := make([]string, 0)
	dfs = func(iter int) {
		if iter == len(allergenToIngredients) {
			out = strings.Join(chosen, ",")
			return
		}
		for _, v := range allergenToIngredients[allergens[iter]] {
			if Index(chosen, v) == -1 {
				chosen = append(chosen, v)
				dfs(iter + 1)
				chosen = chosen[:len(chosen)-1]
			}
		}
	}
	dfs(0)

	return out
}

func Index(arr []string, needle string) int {
	for i, v := range arr {
		if v == needle {
			return i
		}
	}
	return -1
}

func Add(allergenToIngredients map[string][]string, allergen string, ingredient string) {
	if _, ok := allergenToIngredients[allergen]; !ok {
		allergenToIngredients[allergen] = make([]string, 0)
	}

	if Index(allergenToIngredients[allergen], ingredient) == -1 {
		allergenToIngredients[allergen] = append(allergenToIngredients[allergen], ingredient)
	}
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
