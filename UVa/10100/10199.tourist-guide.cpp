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

int time_spent;

// the adjacency list representation of `G`
vector<vector<int> > g;
// the time a vertex `i` was discovered first
vector<int> time_in;
// stores the discovery time of the lowest predecessor that vertex `i`'s
// succesor vertices can reach **through a back edge**, initially
// the lowest predecessor is set to the vertex itself
vector<int> back;
// the articulation points found during the dfs
vector<bool> is_cut_vertex;

void dfs(int v, int parent) {
  // the lowest back edge discovery time of `v` is
  // set to the discovery time of `v` initally
  back[v] = time_in[v] = ++time_spent;
  
  // count the number of children for the `root` vertex
  int children = 0;

  for (int i = 0; i < g[v].size(); i += 1) {
    int next = g[v][i];

    if (next == parent) {
      continue;
    }

    if (time_in[next] == -1) {
      dfs(next, v);
      // if there's a back edge between a descendant of `next` and
      // a predecessor of `v` then `next` will have a lower reachable vertex
      // than `v` through a back edge, in this case the vertex is not an
      // articulation point (the special case of the root node is handled below)
      if (back[next] >= time_in[v] && parent != -1) {
        is_cut_vertex[v] = true;
      }
      // propagation of the back edge to a vertex with the lowest discovery time
      back[v] = min(back[v], back[next]);
      ++children;
    } else {
      // *back edge*
      // update index of the vertex incident with this back edge to
      // be the one with the lowest discovery time
      back[v] = min(back[v], time_in[next]);
    }
  }

  if (parent == -1 && children > 1) {
    is_cut_vertex[v] = true;
  }
}

/**
 * Finds the articulation points in an undirected graph `G`
 * of order`n` and size `m`
 *
 * Time complexity: O(n + m)
 * Space complexity: O(n)
 */
void articulation_points() {
  int n = g.size();
  time_spent = 0;
  time_in.assign(n, -1);
  back.assign(n, -1);
  is_cut_vertex.assign(n, false);

  for (int i = 0; i < n; i += 1) {
    if (time_in[i] == -1) {
      dfs(i, -1);
    }
  }
}

int main() {
	int n, m;
	string from, to;
	int cas = 1;
	while (cin >> n && n) {
		if (cas > 1) {
			NL;
		}

		g.assign(n, vector<int>());

		map<string, int> city_to_vertex;
		vector<string> city(n);

		for (int i = 0; i < n; i += 1) {
			cin >> city[i];
			city_to_vertex[city[i]] = i;
		}

		cin >> m;
		for (int i = 0; i < m; i += 1) {
			cin >> from >> to;
			int u = city_to_vertex[from];
			int v = city_to_vertex[to];
			g[u].push_back(v);
			g[v].push_back(u);
		}

		articulation_points();

		vector<string> ans;
		for (int i = 0; i < n; i += 1) {
			if (is_cut_vertex[i]) {
				ans.push_back(city[i]);
			}
		}
		sort(ans.begin(), ans.end());

		printf("City map #%d: %d camera(s) found\n", cas++, ans.size());
		for (int i = 0; i < ans.size(); i += 1) {
			cout << ans[i] << endl;
		}
	}
	return 0;
}