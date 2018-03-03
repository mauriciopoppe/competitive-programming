package main

import (
	"os"
	"testing"
)

func TestOne(t *testing.T) {
	f, _ := os.Open("./in1")
	ins := ParseOne(f)
	if v := One(ins); v != 1 {
		t.Error(v)
	}
}

func TestTwo(t *testing.T) {
	f, _ := os.Open("./in1")
	ins := ParseOne(f)
	if v := Two(ins); v != 10 {
		t.Error(v)
	}
}
