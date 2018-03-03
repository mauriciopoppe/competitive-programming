package main

import (
	"testing"
)

func TestOne(t *testing.T) {
	var in []string
	in = []string{"s1", "x3/4", "pe/b"}
	if v := One("abcde", in); v != "baedc" {
		t.Error(v)
	}
}
