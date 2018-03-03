package main

import (
	"testing"
)

func TestOne(t *testing.T) {
	var in []int
	in = []int{3, 2, 0, 0, 4, 0, 4}
	if v := One(in); v != 24 {
		t.Error(v)
	}
}

func TestTwo(t *testing.T) {
	var in []int
	in = []int{3, 2, 0, 0, 4, 0, 4}
	if v := Two(in); v != 10 {
		t.Error(v)
	}
}
