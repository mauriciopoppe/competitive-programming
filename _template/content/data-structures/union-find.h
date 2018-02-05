#include "common.h"
#pragma once

struct UnionFind {
  vi rank, p;

  UnionFind(int n) {
    rank.assign(n, 0);
    p.assign(n, -1);
  }

  int find_set(int i) { return p[i] == -1 ? i : p[i] = find_set(p[i]); }
  bool same_set(int i, int j) { return find_set(i) == find_set(j); }
  void union_set(int i, int j) {
    if (!same_set(i, j)) {
      i = find_set(i);
      j = find_set(j);
      if (rank[i] > rank[j]) p[j] = i;
      else {
        p[i] = j;
        if (rank[i] == rank[j]) rank[j]++;
      }
    }
  }
};
