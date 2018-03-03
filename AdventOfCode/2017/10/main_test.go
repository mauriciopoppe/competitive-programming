package main

import (
	"bytes"
	"io"
	"strings"
	"testing"
)

func TestOne(t *testing.T) {
	var in []int
	in = []int{3, 4, 1, 5}
	if v := One(5, in); v != 12 {
		t.Error(v)
	}
	in = []int{1, 1, 1, 1, 1, 1}
	if v := One(5, in); v != 0 {
		t.Error(v)
	}
	in = []int{5}
	if v := One(5, in); v != 12 {
		t.Error(v)
	}
}

func stor(s string) io.Reader {
	buf := make([]byte, len(s))
	io.ReadFull(strings.NewReader(s), buf)
	return bytes.NewReader(buf)
}

func TestTwo(t *testing.T) {
	r := stor("1,2,3")
	in := ParseTwo(r)
	if v := Two(256, in); v != "3efbe78a8d82f29979031a4aa0b16a9d" {
		t.Error(v)
	}
}
