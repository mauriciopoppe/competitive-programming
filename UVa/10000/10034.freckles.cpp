#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define MS(a, v) memset(a, v, sizeof a)
#define NL printf("\n")
#define PI acos(-1)
#define EPS 1e-9
#define TR(ar, it) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )

typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

/**
 * An implementation of Prim's algorithm which computes
 * the minimum spanning tree of a dense graph `G`
 *
 * Time complexity: O(n^2)
 * Space complexity: O(n)
 *
 * @param {vector<vector<int> >} g The adjacency matrix of `G`, each entry `a_{ij}`
 * holds the weight of the edge connecting vertex `i` and vertex `j`, if this number
 * is <= 0 then `i` and `j` are not adjacent
 * @return {int} The weight of the MST
 */
double prim(vector<vector<double> > &g) {
  int n = g.size();
  double INF = numeric_limits<double>::max();
  double total = 0;

  vector<bool> visited(n, false);
  // holds the weight of the edge of minimum weight incident
  // to the vertex `i`
  vector<double> min_cost(n, INF);
  // (optional) holds the index of a vertex adjacent to the
  // vertex `i` in the MST, note that the size of the MST is
  // n - 1 so the first vertex won't store the mentioned index
  vector<int> neighbor_selected(n, -1);

  // pick the first node as the "arbitrary" node
  min_cost[0] = 0;

  for (int i = 0; i < n; i += 1) {
    int v = -1;
    for (int j = 0; j < n; j += 1) {
      // find the vertices which haven't been visited yet
      // among them find a vertex with the minimum edge weight
      if (!visited[j] && (v == -1 ||
          min_cost[j] < min_cost[v])) {
        v = j;
      }
    }

    visited[v] = true;
    total += min_cost[v];

    // update the minimum edge weight of all the vertices
    // adjacent to `v`
    for (int to = 0; to < n; to += 1) {
      if (g[v][to] > 0 &&
          g[v][to] < min_cost[to]) {
        min_cost[to] = g[v][to];
        // update the candidate neighbor of the vertex `to` to
        // be `v` since it's connected with an edge
        // of minimum weight among all the adjacent vertices to `to`
        neighbor_selected[to] = v;
      }
    }
  }

  return total;
}


int main() {
	int cas;
	cin >> cas;
	for (int z = 0; z < cas; z += 1) {
		int n;
		cin >> n;
		vector<vector<double> > g(n, vector<double>(n, 0));

		double x, y;
		vector<pair<double, double> > points(n);
		for (int i = 0; i < n; i += 1) {
			cin >> points[i].first >> points[i].second;
			for (int j = 0; j < i; j += 1) {
				double dist = hypot(
					abs(points[i].first - points[j].first),
					abs(points[i].second - points[j].second)
				);
				g[i][j] = g[j][i] = dist;
			}
		}

		// for (int i = 0; i < n; i += 1) {
		// 	for (int j = 0; j < n; j += 1) {
		// 		printf("%f ", g[i][j]);
		// 	}
		// 	NL;
		// }

		if (z) NL;
		printf("%.2f\n", prim(g));
	}
	return 0;
}