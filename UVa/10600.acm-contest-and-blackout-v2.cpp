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

#define N 200004
int parent[N];
int rank[N];
int satellites;
int n_nodes, n_edges;

struct edge {
    int from, to;
    int weight;
    bool mst;
    bool disabled;
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

int n_sets() {
	set<int> s;
	F(i, n_nodes) {
		s.insert(find_root(i));
	}
	return s.size();
}

int kruskal(vector<edge> &edges, bool is_first) {
	int total = 0;
	int u, v;
    sort(edges.begin(), edges.end());
    for(int i = 0; i < edges.size(); i += 1) {
    	if (edges[i].disabled) {
    		continue;
    	}
        u = find_root(edges[i].from);
        v = find_root(edges[i].to);
        if(u != v) {
        	if (is_first) {
        		edges[i].mst = true;
        	}
        	set_union(u, v);
    		total += edges[i].weight;        		
        }
    }

    set<int> groups;
    F(i, n_nodes) {
    	groups.insert(find_root(i));
    }

    return groups.size() == 1 ? total : INF;
}

void read_and_solve() {
	edge e;
	vector<edge> edges;
	F(i, n_edges) {		
		cin >> e.from >> e.to >> e.weight;
		e.mst = false;
		e.disabled = false;
		--e.from; --e.to;
		edges.push_back(e);
	}
	int mn = kruskal(edges, true);
	int mn_next = INF;
	F(i, n_edges) {
		if (edges[i].mst) {
			init_sets(n_nodes);
			edges[i].disabled = true;
			int t = kruskal(edges, false);
			printf("%d\n", t);
			mn_next = min(t, mn_next);
			edges[i].disabled = false;
		}
	}
	printf("%d %d\n", mn, mn_next);
}

int main() {
	int cas;
	cin >> cas;
	while (cas--) {
		cin >> n_nodes >> n_edges;
		init_sets(n_nodes);
		read_and_solve();
	}
	return 0;
}