package main

import (
	"testing"
)

func TestOne(t *testing.T) {
	var in []string
	in = []string{"ne", "ne", "ne"}
	if v := One(in); v != 3 {
		t.Error(v)
	}
	in = []string{"se", "sw", "se", "sw", "sw"}
	if v := One(in); v != 3 {
		t.Error(v)
	}
}
