package main

import (
	"io"
	"strings"
	"testing"
)

func TestTwo(t *testing.T) {
	type args struct {
		r io.Reader
	}

	r := strings.NewReader(strings.TrimSpace(`
abc

a
b
c

ab
ac

a
a
a
a

b
`))

	tests := []struct {
		name string
		args args
		want int
	}{
		{"Two", args{r}, 6},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := Two(tt.args.r); got != tt.want {
				t.Errorf("Two() = %v, want %v", got, tt.want)
			}
		})
	}
}
