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

struct edge {
	int to, weight, state, visited;
	edge() {}
	edge(int _to, int _weight, int _state) {
		to = _to;
		weight = _weight;
		state = _state;
		visited = 0;
	}
};

vector<vector<edge> > g;

typedef pair<vector<int>, vector<int> > pvv;

pvv prim() {
	int n = g.size();

	vector<bool> visited(n, false);
	vector<int> neighbor(n, -1);
	vector<int> min_cost(n, INT_MAX);

	min_cost[0] = 0;

	// (weight, vertex)
	set<pair<int, int> > q;
	q.insert({0, 0});

	while (!q.empty()) {
		int top = q.begin()->second;
		visited[top] = true;

		q.erase(q.begin());
		for (int i = 0; i < g[top].size(); i += 1) {
			int to = g[top][i].to;
			int weight = g[top][i].weight;

			if (g[top][i].state && !visited[to] && weight < min_cost[to]) {
				q.erase({ min_cost[to], to });
				min_cost[to] = weight;
				neighbor[to] = top;
				q.insert({ min_cost[to], to });
			}
		}		
	}
	
	return {neighbor, min_cost};
}

int mst_cost(pvv mst) {
	int cost = 0;
	for (int i = 0; i < g.size(); i += 1) {
		// printf("%d>%d w=%d, ", i + 1, mst.first[i] + 1, mst.second[i]);
		if (mst.second[i] == INT_MAX) {
			return INT_MAX;
		}
		cost += mst.second[i];
	}
	// NL;
	// cout << cost << endl;
	return cost;
}

void update_state(int from, int to, int weight, int state) {
	for (int i = 0; i < g[from].size(); i += 1) {
		if (g[from][i].to == to && g[from][i].weight == weight) {
			g[from][i].state = state;
			++total;
			break;
		}
	}

	for (int i = 0; i < g[to].size(); i += 1) {
		if (g[to][i].to == from && g[to][i].weight == weight) {
			g[to][i].state = state;
			break;
		}
	}
}

void solve() {
	int n = g.size();
	pvv mst = prim();
	int first_min = mst_cost(mst);
	int second_min = INT_MAX;
	for (int i = 1; i < n; i += 1) {
		update_state(i, mst.first[i], mst.second[i], 0);

		pvv mst2 = prim();
		second_min = min(second_min, mst_cost(mst2));

		update_state(i, mst.first[i], mst.second[i], 1);
	}
	cout << first_min << " " << second_min << endl;
}

int main() {
	int cas;
	cin >> cas;
	while (cas--) {
		int n, m;
		cin >> n >> m;
		g.assign(n, vector<edge>());

		int from, to, weight;
		for (int i = 0; i < m; i += 1) {
			cin >> from >> to >> weight;
			--from;
			--to;
			g[from].push_back(edge(to, weight, 1));
			g[to].push_back(edge(from, weight, 1));
		}

		solve();
	}
	return 0;
}