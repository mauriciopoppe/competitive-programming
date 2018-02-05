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

#define N 1005
int parent[N];
int rank[N];
int nodes, edges;
struct edge {
	int index;
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

vi kruskal(vector<edge> &edges) {
	// the weight of MST
    vector<int> bad_edges;
    // vertices in each edge
    int u, v;
    sort(edges.begin(), edges.end());
    for(int i = 0; i < edges.size(); i += 1) {
        u = find_root(edges[i].from);
        v = find_root(edges[i].to);
        if (u != v) {
            set_union(u, v);
        } else {
        	bad_edges.push_back(edges[i].weight);
        }
    }
    return bad_edges;
}

void read_and_solve() {
	edge e;
	vector<edge> all_edges;
	F(i, edges) {
		cin >> e.from >> e.to >> e.weight;
		e.index = i + 1;
		all_edges.push_back(e);
	}

	vi solution = kruskal(all_edges);
	if (!solution.size()) puts("forest");
	else {
		F(i, solution.size()) {
			if (i) printf(" ");
			printf("%d", solution[i]);
		}
		NL;
	}

}

int main() {
	while (cin >> nodes >> edges) {
		if (nodes + edges == 0) {
			break;
		}
		init_sets(nodes);
		read_and_solve();
	}
	return 0;
}