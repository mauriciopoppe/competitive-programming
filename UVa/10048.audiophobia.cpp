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

#define N 105
int parent[N];
int rank[N];

int q[N][N];

int n_nodes, n_edges, n_queries;

struct edge {
    int from, to;
    int weight;
    bool operator < (const edge &other) const {
        return weight < other.weight;
    }
};

void init_sets(int nodes) {
	for (int i = 0; i < nodes; i += 1) {
		parent[i] = i;
		rank[i] = 1;
	}
}

int find_root(int node) {
	if (parent[node] != node) {
		parent[node] = find_root(parent[node]);
	}
	return parent[node];
}

void set_union(int x, int y) {
	int rx = find_root(x);
	int ry = find_root(y);
	if (rx == ry) {
		return;
	}
	if (rank[rx] > rank[ry]) {
		parent[ry] = rx;
		rank[rx] += rank[ry];
	} else {
		parent[rx] = ry;
		rank[ry] += rank[rx];
	}
}

void calc(int total) {
	F(i, n_nodes) {
		for (int j = i + 1; j < n_nodes; j += 1) {
			int u = find_root(i);
			int v = find_root(j);
			if (u == v) {
				q[i][j] = q[j][i] = min(q[i][j], total);
			}
		}
	}
}

int kruskal(vector<edge> &edges) {
	// vertices in each edge
    int u, v;
    sort(edges.begin(), edges.end());
    for(int i = 0; i < edges.size(); i += 1) {
        u = find_root(edges[i].from);
        v = find_root(edges[i].to);
        if(u != v) {
            set_union(u, v);
            calc(edges[i].weight);
        }
    }
}

void reset() {
	F(i, n_nodes) {
		F(j, n_nodes) {
			q[i][j] = INF;
		}
	}
}

void read() {
	edge e;
	vector<edge> edges;
	F(i, n_edges) {
		cin >> e.from >> e.to >> e.weight;
		--e.from; --e.to;
		edges.push_back(e);
	}
	kruskal(edges);
}

void solve() {
	int from, to;
	F(i, n_queries) {
		cin >> from >> to;
		--from; --to;
		if (q[from][to] != INF) {
			printf("%d\n", q[from][to]);
		} else {
			printf("no path\n");
		}
	}
}

int main() {
	int cas = 0;
	while (cin >> n_nodes >> n_edges >> n_queries) {
		if (n_nodes == 0) {
			break;
		}
		init_sets(n_nodes);
		reset();
		read();
		if (cas) printf("\n");
		printf("Case #%d\n", ++cas);
		solve();
	}
	return 0;
}