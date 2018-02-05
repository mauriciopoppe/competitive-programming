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

int prim(vector<vector<pair<int, int> > > &g) {
  int n = g.size();
  int total = 0;
  vector<bool> visited(n, false);
  vector<int> min_cost(n, INF);
  set<pair<int, int> > q;
  q.insert({0, 0});
  min_cost[0] = 0;

  while (!q.empty()) {
    assert(q.size() <= n - 1);

    int v = q.begin()->second;
    total += q.begin()->first;
    q.erase(q.begin());
    visited[v] = true;

    for (int i = 0; i < g[v].size(); i += 1) {
      pair<int, int> &next = g[v][i];

      int to = next.first;
      int weight = next.second;

      if (!visited[to] && weight < min_cost[to]) {
        q.erase({ min_cost[to], to });
        min_cost[to] = weight;
        q.insert({ min_cost[to], to });
      }
    }
  }
  return total;
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) {
			break;
		}

		vector<vector<pair<int, int> > > g;
		g.assign(n, vector<pair<int, int> > ());
		int from, to, weight;
		int total = 0;
		
		for(int i = 0; i < m; i += 1) {
			cin >> from >> to >> weight;
			g[from].push_back({ to, weight });
			g[to].push_back({ from, weight });
			total += weight;
		}
		cout << total - prim(g) << endl;
	}
	return 0;
}