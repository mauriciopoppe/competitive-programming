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

// adjacency list of G
vector<vector<int> > g;
vector<int> time_in;
vector<int> order;

int dfs_topological_sort(int v) {
  time_in[v] = 1;
  for (int i = 0; i < g[v].size(); i += 1) {
    int to = g[v][i];
    if (time_in[to] == -1) {
      dfs_topological_sort(to);
    }
  }

  order.push_back(v);
}

void topological_sort() {
  int n = g.size();
  time_in.assign(n, -1);
  order.clear();
  for (int i = 0; i < n; i += 1) {
    if (time_in[i] == -1) {
      dfs_topological_sort(i);
    }
  }
  reverse(order.begin(), order.end());
}

int solve() {
	int n = g.size();
  topological_sort();  
  time_in.assign(n, -1);
  int total = 0;
  for (int i = 0; i < n; i += 1) {
    if (time_in[order[i]] == -1) {
      dfs_topological_sort(order[i]);
      ++total;
    }
  }
  return total;
}

int main() {
	int cas;
	cin >> cas;
	while (cas--) {
		int n, m;
		int from, to;
		cin >> n >> m;
		g.assign(n, vector<int>());

		for (int i = 0; i < m; i += 1) {
			cin >> from >> to;
			g[from - 1].push_back(to - 1);
		}

		cout << solve() << endl;
	}
	return 0;
}