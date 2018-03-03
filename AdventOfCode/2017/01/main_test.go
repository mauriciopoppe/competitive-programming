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
	s := "1144"
	if One(stor(s)) != 5 {
		t.Error()
	}
}

func TestTwo(t *testing.T) {
	var s string
	s = "1212"
	if v := Two(stor(s)); v != 6 {
		t.Error(v)
	}
	s = "123123"
	if v := Two(stor(s)); v != 12 {
		t.Error(v)
	}
	s = "12131415"
	if v := Two(stor(s)); v != 4 {
		t.Error(v)
	}
}
