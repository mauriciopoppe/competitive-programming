package main

import "testing"

func TestOne(t *testing.T) {
	v := []int{0, 2, 7, 0}
	if ans := One(v); ans != 5 {
		t.Error(ans)
	}
}

func TestTwo(t *testing.T) {
	v := []int{0, 2, 7, 0}
	if ans := Two(v); ans != 4 {
		t.Error(ans)
	}
}
