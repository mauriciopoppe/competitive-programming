package main

import (
	"bytes"
	"io"
	"strings"
	"testing"
)

func stor(s string) io.Reader {
	buf := make([]byte, len(s))
	sr := strings.NewReader(s)
	if _, err := io.ReadFull(sr, buf); err != nil {
		panic(err)
	}
	return bytes.NewReader(buf)
}

func TestOne(t *testing.T) {
	s := "5 1 9 5\n7 5 3\n2 4 6 8"
	if v := One(stor(s)); v != 18 {
		t.Error(v)
	}
}

func TestTwo(t *testing.T) {
	s := "5 9 2 8\n9 4 7 3\n3 8 6 5"
	if v := Two(stor(s)); v != 9 {
		t.Error(v)
	}
}
