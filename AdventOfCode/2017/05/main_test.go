package main

import (
	"bytes"
	"io"
	"strings"
	"testing"
)

func stor(s string) io.Reader {
	buf := make([]byte, len(s))
	io.ReadFull(strings.NewReader(s), buf)
	return bytes.NewReader(buf)
}

func TestOne(t *testing.T) {
	var r io.Reader
	r = stor("0\n3\n0\n1\n-3")
	if v := One(r); v != 5 {
		t.Error(v)
	}
}

func TestTwo(t *testing.T) {
	var r io.Reader
	r = stor("0\n3\n0\n1\n-3")
	if v := Two(r); v != 10 {
		t.Error(v)
	}
}
