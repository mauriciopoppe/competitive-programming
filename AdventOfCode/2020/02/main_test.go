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

	oneArg := strings.NewReader(strings.TrimSpace(`
3-4 t: dttt
5-7 l: llmlqmblllh
3-10 g: gggxwxggggkgglklhhgg
`))

	tests := []struct {
		name string
		args args
		want int
	}{
		// TODO: Add test cases.
		{"One", args{oneArg}, 2},
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
3-4 t: dttt
4-7 l: llmlqmblllh
4-5 g: gggxwxggggkgglklhhgg
`))

	tests := []struct {
		name string
		args args
		want int
	}{
		{"Two", args{r}, 1},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := Two(tt.args.r); got != tt.want {
				t.Errorf("Two() = %v, want %v", got, tt.want)
			}
		})
	}
}
