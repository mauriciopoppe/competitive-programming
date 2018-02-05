#include "common.h"
#pragma once

int edmondsKarp(vector<unordered_map<int, int>>& graph, int source, int target) {
  int flow = 0;
  vi par(sz(graph)), q(sz(graph));
  while (true) {
    fill(all(par), -1);
    par[source] = 0;
    q[0] = source;
    int ptr = 1;
    rep(i, 0, ptr) {
      int x = q[i];
      if (x == target) break;
      trav(e, graph[x]) {
        int y = e.first;
        int w = e.second;
        if (par[y] == -1 && w > 0) {
          par[y] = x;
          q[ptr++] = y;
        }
      }
    }

    if (par[target] == -1) return flow;
    int min_w = numeric_limits<int>::max();
    for (int y = target; y != source; y = par[y]) {
      min_w = min(min_w, graph[par[y]][y]);
    }
    flow += min_w;
    for (int y = target; y != source; y = par[y]) {
      int p = par[y];
      if ((graph[p][y] -= min_w) <= 0) graph[p].erase(y);
      graph[y][p] += min_w;
    }
  }
}
