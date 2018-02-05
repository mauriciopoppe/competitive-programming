#include <bits/stdc++.h>
#define INF int(1e9*2)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int time_spent;
vector<pii> ans;
vector<int> tin, bck;
vector<vi> graph;

void dfs(int v, int parent) {
  bck[v] = tin[v] = ++time_spent;
  for (int nxt: graph[v]) {
    if (nxt == parent) continue;
    if (tin[nxt] == -1) {
      dfs(nxt, v);
      if (bck[nxt] > tin[v]) {
        ans.push_back({min(v, nxt), max(v, nxt)});
      }
      bck[v] = min(bck[v], bck[nxt]);
    } else {
      bck[v] = min(bck[v], tin[nxt]);
    }
  }
}

void bridges() {
  int n = graph.size();
  ans.clear();
  tin.assign(n, -1);
  bck.assign(n, -1);
  time_spent = 0;
  for (int i = 0; i < n; i += 1) {
    if (tin[i] == -1) {
      dfs(i, -1);
    }
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  int n;
  while (cin >> n) {
    graph.assign(n, vector<int>());
    for (int z = 0; z < n; z += 1) {
      int a, b, con;
      scanf("%d (%d)", &a, &con);
      for (int i = 0; i < con; i += 1) {
        cin >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
      }
    }
    bridges();
    sort(ans.begin(), ans.end());

    printf("%d critical links\n", (int)ans.size());
    for (auto e: ans) {
      printf("%d - %d\n", e.first, e.second);
    }
    printf("\n");
  }
}
