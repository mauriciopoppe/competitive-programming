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
	r = stor("a b c\na a b")
	if v := One(r); v != 1 {
		t.Error(v)
	}
	r = stor("a b c\nb c d\nc d e\n e a\n i i")
	if v := One(r); v != 4 {
		t.Error(v)
	}
}

func TestTwo(t *testing.T) {
	var r io.Reader
	r = stor("a b c\na a b")
	if v := Two(r); v != 1 {
		t.Error(v)
	}
	r = stor("ab ba\nabc cba")
	if v := Two(r); v != 0 {
		t.Error(v)
	}
}
