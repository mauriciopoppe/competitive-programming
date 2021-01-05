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

	r := strings.NewReader(strings.TrimSpace(`
Player 1:
9
2
6
3
1

Player 2:
5
8
4
7
10
`))

	tests := []struct {
		name string
		args args
		want int
	}{
		{"One", args{r}, 306},
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

	r := strings.NewReader(strings.TrimSpace(`
Player 1:
9
2
6
3
1

Player 2:
5
8
4
7
10
`))

	r2 := strings.NewReader(strings.TrimSpace(`
Player 1:
43
19

Player 2:
2
29
14
`))

	tests := []struct {
		name string
		args args
		want int
	}{
		{"Two", args{r}, 291},
		{"TwoB", args{r2}, 105},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := Two(tt.args.r); got != tt.want {
				t.Errorf("Two() = %v, want %v", got, tt.want)
			}
		})
	}
}
