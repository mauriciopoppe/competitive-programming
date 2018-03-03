package main

import (
	"testing"
)

func TestOne(t *testing.T) {
	if v := One("{}"); v != 1 {
		t.Error(v)
	}
	if v := One("{{{}}}"); v != 6 {
		t.Error(v)
	}
	if v := One("{{{}}}"); v != 6 {
		t.Error(v)
	}
	if v := One("{{<ab>},{<ab>},{<ab>},{<ab>}}"); v != 9 {
		t.Error(v)
	}
	if v := One("{{<a!>},{<a!>},{<a!>},{<ab>}}"); v != 3 {
		t.Error(v)
	}
}

func TestTwo(t *testing.T) {
	if v := Two("<>"); v != 0 {
		t.Error(v)
	}
	if v := Two("<random characters>"); v != 17 {
		t.Error(v)
	}
	if v := Two("<{!>}>"); v != 2 {
		t.Error(v)
	}
	if v := Two("<<<<>"); v != 3 {
		t.Error(v)
	}
	if v := Two("<{o\"i!a,<{i<a>"); v != 10 {
		t.Error(v)
	}
}
