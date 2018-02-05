#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define MS(a, v) memset(a, v, sizeof a)
#define NL printf("\n")
#define INF 1e9
#define PI acos(-1)
#define EPS 1e-9
#define TR(ar, it) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )

typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<bool> visited;
vector<vector<int> > g;
vector<int> order;

void dfs(int v) {
  visited[v] = true;
  for (int i = 0; i < g[v].size(); i += 1) {
    int next = g[v][i];
    if (!visited[next]) {
      dfs(next);
    }
  }
  order.push_back(v);
}

/**
 * Given a graph `G` of order `n` and size `m` computes a linear ordering
 * of the vertices such that for every edge u -> v, `u` comes earlier than `v`
 * in the ordering
 *
 * Time complexity: O(n + m)
 * Space complexity: O(n)
 *
 */
void topological_sorting() {
  int n = g.size();
  visited.assign(n, false);
  order.clear();
  
  for (int i = 0; i < visited.size(); i += 1) {
    if (!visited[i]) {
      dfs(i);
    }
  }

  reverse(order.begin(), order.end());
}

int main() {
	int n, m;
	int from, to;
	while (cin >> n >> m && n + m != 0) {
		g.assign(n, vector<int>());
		for (int i = 0; i < m; i += 1) {
			cin >> from >> to;
			g[from - 1].push_back(to - 1);
		}
		topological_sorting();
		for (int i = 0; i < order.size(); i += 1) {
			if (i) printf(" ");
			printf("%d", order[i] + 1);
		}
		NL;
	}
	return 0;
}