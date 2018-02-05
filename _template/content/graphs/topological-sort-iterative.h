#include "common.h"

#pragma once

vi topo_sort(vector<vi> &graph) {
  int n = graph.size();
  vi indeg(n);
  rep(i, 0, n) {
    trav(j, graph[i]) {
      indeg[j]++;
    }
  }
  queue<int> q; // use priority queue for lexic. smallest ans.
  rep(i, 0, n) {
    if (indeg[i] == 0) {
      q.push(-i);
    }
  }
  vi topsort;
  while (q.size() > 0) {
    int i = -q.front(); // top() for priority queue
    topsort.push_back(i);
    q.pop();
    trav(j, graph[i]) {
      if (--indeg[j] == 0) {
        q.push(-j);
      }
    }
  }
  return topsort;
}
