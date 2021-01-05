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
5764801
17807724
`))
	a, b := One(r)

	wanted := 14897079
	if a != b || a != wanted {
		t.Errorf("wanted=%v a=%v b=%v", wanted, a, b)
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
