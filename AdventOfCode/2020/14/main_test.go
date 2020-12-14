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
mask = XXXXXXXXXXXXXXXXXXXXXXXXXXXXX1XXXX0X
mem[8] = 11
mem[7] = 101
mem[8] = 0
`))

	tests := []struct {
		name string
		args args
		want uint64
	}{
		{"One", args{r}, 165},
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
mask = 000000000000000000000000000000X1001X
mem[42] = 100
mask = 00000000000000000000000000000000X0XX
mem[26] = 1
`))

	tests := []struct {
		name string
		args args
		want uint64
	}{
		{"One", args{r}, 208},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := Two(tt.args.r); got != tt.want {
				t.Errorf("Two() = %v, want %v", got, tt.want)
			}
		})
	}
}
