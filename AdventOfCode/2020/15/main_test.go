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

	r := strings.NewReader(strings.TrimSpace(`0,3,6`))

	tests := []struct {
		name string
		args args
		want int
	}{
		{"One", args{r}, 436},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := One(tt.args.r, 2020); got != tt.want {
				t.Errorf("One() = %v, want %v", got, tt.want)
			}
		})
	}
}

func TestTwo(t *testing.T) {
	type args struct {
		r io.Reader
	}

	r := strings.NewReader(strings.TrimSpace(``))

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
