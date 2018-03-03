package main

import (
	"os"
	"testing"
)

func TestOne(t *testing.T) {
	f, _ := os.Open("./in1")
	s, m := ParseOne(f)
	if v := One(s, m); v != "tknk" {
		t.Error(v)
	}
}

func TestTwo(t *testing.T) {
	f, _ := os.Open("./in1")
	f.Seek(0, 0)
	s, m := ParseOne(f)
	solOne := One(s, m)
	f.Seek(0, 0)
	s2, m2 := ParseTwo(f)
	if v := Two(solOne, s2, m2); v != 60 {
		t.Error(v)
	}
}
