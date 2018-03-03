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
	r = stor("1")
	if v := One(r); v != 0 {
		t.Error(v)
	}
	r = stor("13")
	if v := One(r); v != 4 {
		t.Error(v)
	}
}

func TestTwo(t *testing.T) {
	var r io.Reader
	r = stor("1")
	if v := Two(r); v != 2 {
		t.Error(v)
	}
	r = stor("123")
	if v := Two(r); v != 133 {
		t.Error(v)
	}
}
