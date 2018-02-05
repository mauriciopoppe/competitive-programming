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

int nodes, edges;
#define N 200004
int parent[N];
int rank[N];

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

int kruskal(vector<edge> &edges) {
	// the weight of MST
    int total = 0;
    // vertices in each edge
    int u, v;
    sort(edges.begin(), edges.end());
    for(int i = 0; i < edges.size(); i += 1) {
        u = find_root(edges[i].from);
        v = find_root(edges[i].to);
        if(u != v) {
            set_union(u, v);
            total += edges[i].weight;
        }
    }
    return total;
}

int main() {
	edge e;
	while (cin >> nodes >> edges && nodes + edges != 0) {
		init_sets(nodes);
		vector<edge> graph_edges;
		int total = 0;
		F(i, edges) {
			cin >> e.from >> e.to >> e.weight;
			total += e.weight;
			graph_edges.push_back(e);
		}
		printf("%d\n", total - kruskal(graph_edges));
	}
	return 0;
}