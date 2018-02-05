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

struct Point {
	double x, y;
	Point(){}
	Point(double a, double b) { x = a; y = b; }
};
double dist(const Point &A, const Point &B) {
	return hypot(A.x - B.x, A.y - B.y);
}

#define N 200004
int parent[N];
int rank[N];
int satellites;
int nodes;

struct edge {
    int from, to;
    double weight;
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

bool solved() {
	set<int> s;
	F(i, nodes) {
		s.insert(find_root(i));
	}
	return s.size() == satellites;
}

double kruskal(vector<edge> &edges) {
	double total = 0;
    int u, v;
    sort(edges.begin(), edges.end());
    for(int i = 0; i < edges.size(); i += 1) {
        u = find_root(edges[i].from);
        v = find_root(edges[i].to);
        if (solved()) {
        	return total;
        }
        if(u != v) {
            set_union(u, v);
            total = edges[i].weight;
        }
    }
    return total;
}

void read_and_solve() {
	edge e;
	double x, y;
	vector<Point> P;
	F(i, nodes) {
		cin >> x >> y;
		P.push_back(Point(x, y));
	}

	vector<edge> edges;
	F(i, nodes) {
		FOR(j, i + 1, nodes) {
			e.from = i;
			e.to = j;
			e.weight = dist(P[i], P[j]);
			edges.push_back(e);
		}
	}
	printf("%.2lf\n", kruskal(edges));
}

int main() {
	int cas;
	cin >> cas;
	while (cas--) {
		cin >> satellites >> nodes;
		init_sets(nodes);
		read_and_solve();
	}
	return 0;
}