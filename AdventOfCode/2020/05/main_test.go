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
FBFBBFFRLR
`))

	tests := []struct {
		name string
		args args
		want int
	}{
		{"One", args{oneArg}, 357},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := One(tt.args.r); got != tt.want {
				t.Errorf("One() = %v, want %v", got, tt.want)
			}
		})
	}
}
