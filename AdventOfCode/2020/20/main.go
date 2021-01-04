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

type Tile struct {
	id     uint64
	x, y   int
	solved bool
	board  [][]byte
}

func (t *Tile) Print() {
	fmt.Println("========")
	for i := 0; i < len(t.board); i++ {
		fmt.Println(string(t.board[i]))
	}
	fmt.Println("========")
}

func (t *Tile) Rotate() {
	R := len(t.board)
	C := len(t.board[0])
	for i := 0; i < R/2; i++ {
		for j := i; j < C-i-1; j++ {
			temp := t.board[i][j]
			t.board[i][j] = t.board[R-j-1][i]
			t.board[R-j-1][i] = t.board[R-i-1][C-j-1]
			t.board[R-i-1][C-j-1] = t.board[j][C-i-1]
			t.board[j][C-i-1] = temp
		}
	}
}

func (t *Tile) Flip() {
	R := len(t.board)
	C := len(t.board[0])
	for i := 0; i < R; i++ {
		for j := 0; j < C/2; j++ {
			temp := t.board[i][j]
			t.board[i][j] = t.board[i][C-j-1]
			t.board[i][C-j-1] = temp
		}
	}
}

func (t *Tile) Border(i int) string {
	if i == 0 {
		return string(t.board[0])
	} else if i == 2 {
		return string(t.board[len(t.board)-1])
	} else {
		col := 0
		if i == 1 {
			col = len(t.board[0]) - 1
		}
		out := make([]byte, 0)
		for i := 0; i < len(t.board); i++ {
			out = append(out, t.board[i][col])
		}
		return string(out)
	}
}

func (t *Tile) Match(other *Tile) bool {
	dx := []int{0, 1, 0, -1}
	dy := []int{1, 0, -1, 0}
	for i := 0; i < len(t.board); i++ {
		for j := 0; j < 8; j++ {

			k := (i + 2) % 4
			if t.Border(i) == other.Border(k) {
				other.x = t.x + dx[i]
				other.y = t.y + dy[i]
				return true
			}
			other.Rotate()
			if j == 3 {
				other.Flip()
			}
		}
	}
	return false
}

func (t *Tile) FindMonsterAt(x, y int) bool {
	pattern := []string{
		"                  # ",
		"#    ##    ##    ###",
		" #  #  #  #  #  #   ",
	}
	for i := 0; i < len(pattern); i++ {
		for j := 0; j < len(pattern[0]); j++ {
			if pattern[i][j] == '#' && (x+i >= len(t.board) || y+j >= len(t.board[0]) || t.board[x+i][y+j] != '#') {
				return false
			}
		}
	}
	return true
}

func (t *Tile) FindMonsters() (int, bool) {
	R := len(t.board)
	C := len(t.board[0])
	monsters := 0
	hash := 0
	for i := 0; i < R; i++ {
		for j := 0; j < C; j++ {
			if t.board[i][j] == '#' {
				hash++
			}
			if t.FindMonsterAt(i, j) {
				monsters++
			}
		}
	}
	if monsters == 0 {
		return 0, false
	}
	return hash - (monsters * 15), true
}

func getTiles(r io.Reader) []Tile {
	scanner := bufio.NewScanner(r)
	tiles := make([]Tile, 0)
	for scanner.Scan() {
		t := Tile{}
		_, err := fmt.Sscanf(scanner.Text(), "Tile %d:", &t.id)
		check(err)

		for scanner.Scan() {
			str := scanner.Text()
			if len(str) == 0 {
				break
			}
			t.board = append(t.board, []byte(str))
		}
		tiles = append(tiles, t)
	}
	return tiles
}

// One solution
func One(r io.Reader) uint64 {
	tiles := getTiles(r)
	var total uint64 = 1

	q := []int{0}
	tiles[0].solved = true

	for i := 0; i < len(q); i++ {
		cnt := 0

		for j := 0; j < len(tiles); j++ {
			if tiles[j].solved {
				continue
			}

			ok := tiles[q[i]].Match(&tiles[j])
			if ok {
				cnt++
				tiles[j].solved = true
				q = append(q, j)
			}
		}
	}

	type Pair struct {
		x, y int
	}
	check := make(map[Pair]bool)
	for i := 0; i < len(q); i++ {
		state := Pair{tiles[i].x, tiles[i].y}
		if check[state] {
			panic("tile with same x,y found")
		}
		check[state] = true
	}

	dx := []int{0, 1, 0, -1}
	dy := []int{1, 0, -1, 0}
	for _, tile := range tiles {
		cnt := 0
		for j := 0; j < 4; j++ {
			state := Pair{tile.x + dx[j], tile.y + dy[j]}
			if check[state] {
				cnt++
			}
		}
		if cnt == 2 {
			total *= tile.id
		}
	}

	return total
}

// Two solution
func Two(r io.Reader) uint64 {
	tiles := getTiles(r)
	var total uint64 = 1

	q := []int{0}
	tiles[0].solved = true

	for i := 0; i < len(q); i++ {
		cnt := 0

		for j := 0; j < len(tiles); j++ {
			if tiles[j].solved {
				continue
			}

			ok := tiles[q[i]].Match(&tiles[j])
			if ok {
				cnt++
				tiles[j].solved = true
				q = append(q, j)
			}
		}
	}

	type Pair struct {
		x, y int
	}
	check := make(map[Pair]Tile)
	maxX, maxY := -1000, -1000
	minX, minY := 1000, 1000
	for i := 0; i < len(q); i++ {
		state := Pair{tiles[i].x, tiles[i].y}
		if tiles[i].x < minX {
			minX = tiles[i].x
		}
		if tiles[i].y < minY {
			minY = tiles[i].y
		}
		if tiles[i].x > maxX {
			maxX = tiles[i].x
		}
		if tiles[i].y > maxY {
			maxY = tiles[i].y
		}
		if _, ok := check[state]; ok {
			panic("tile with same x,y found")
		}
		check[state] = tiles[i]
	}

	M := len(tiles[0].board)
	R := (maxY - minY + 1) * (M - 2)
	C := (maxX - minX + 1) * (M - 2)
	out := make([][]byte, 0)
	for i := 0; i < R; i++ {
		out = append(out, make([]byte, C))
	}

	for x := minX; x <= maxX; x++ {
		for y := maxY; y >= minY; y-- {
			tile := check[Pair{x, y}]
			sx := (maxY - y) * (M - 2)
			sy := (x - minX) * (M - 2)
			for i := 1; i < M-1; i++ {
				for j := 1; j < M-1; j++ {
					out[sx+i-1][sy+j-1] = tile.board[i][j]
				}
			}
		}
	}

	t := Tile{1, 0, 0, true, out}
	for i := 0; i < 8; i++ {
		if cnt, found := t.FindMonsters(); found {
			return uint64(cnt)
		}

		t.Rotate()
		if i == 3 {
			t.Flip()
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
