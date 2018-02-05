#include <bits/stdc++.h>
using namespace std;

#define INF (int)1e9
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void edmondsKarp(vector<map<int, int>>& graph, int source, int target) {
  int flow = 0;
  int total_flow = 0;
  trav(e, graph[0]) {
    total_flow += e.second;
  }
  vi par(sz(graph)), q(sz(graph));
  vi ctoa(10, -1);
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

    if (par[target] == -1) break;
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
  if (flow != total_flow) printf("!\n");
  else {
    vi sol(10, '_');
    for (int i = 1; i <= 26; i += 1) {
      trav(e, graph[i]) {
        if (e.first > i && e.second != INF) {
          sol[e.first - 26 - 1] = i - 1 + 'A';
        }
      }
    }
    rep(i, 0, 10) printf("%c", (char)sol[i]);
    printf("\n");
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);

  while (true) {
    string s;
    vector<map<int, int>> graph(1 + 26 + 10 + 1);
    while (true) {
      getline(cin, s);
      if (cin.eof() || s.size() == 0) break;

      int app = s[0] - 'A' + 1;
      int users = s[1] - '1' + 1;

      graph[0][app] += users;

      rep(i, 3, s.size() - 1) {
        if (isdigit(s[i])) {
          int computer = s[i] - '0' + (1 + 26);
          graph[app][computer] = INF;
          graph[computer][26 + 10 + 1] = 1;
        }
      }
    }

    edmondsKarp(graph, 0, 26 + 10 + 1);
    if (cin.eof()) break;
  }
}
