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
	Point(double _x, double _y) {
		x = _x;
		y = _y;
	}
};

#define M 1001
double d[M][M];
bool g[M][M];
int visited[M];
int nodes;
double r;

double cities[M][M];

int total_cities;

vector<Point> P;
int parent[M];
int rank[M];
struct edge {
    int from, to;
    double weight;
    edge(){}
    edge(int f, int t, double w) {
    	from = f;
    	to = t;
    	weight = w;
    }
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

double kruskal(vector<edge> &edges) {
	// the weight of MST
    double total = 0;
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

double get_dist(const Point &A, const Point &B) {
	return hypot(A.x - B.x, A.y - B.y);
}

void reset() {
	total_cities = 0;
	P.clear();
	F(i, M) {
		visited[i] = -1;		
		F(j, M) {
			g[i][j] = 0;
			d[i][j] = 1e10;
			cities[i][j] = 1e10;
		}
	}
}

void dfs(vector<edge> &e, int n) {
	visited[n] = total_cities;
	F(i, nodes) {
		if (g[n][i]) {
			e.push_back(edge(n, i, d[n][i]));
			if (visited[i] == -1) {
				dfs(e, i);
			}
		}
	}
}

void solve() {
	F(i, nodes) {
		for (int j = i + 1; j < nodes; j += 1) {
			d[i][j] = d[j][i] = get_dist(P[i], P[j]);
			if (d[i][j] <= r) {
				g[i][j] = g[j][i] = true;
			}
		}
	}

	double total = 0;
	F(i, nodes) {
		if (visited[i] == -1) {
			vector<edge> city_edges;
			dfs(city_edges, i);
			++total_cities;
			total += kruskal(city_edges);
		}
	}

	F(i, nodes) {
		for (int j = i + 1; j < nodes; j += 1) {
			int from = visited[i];
			int to = visited[j];
			if (from != to) {
				cities[from][to] = min(cities[from][to], d[i][j]);
				cities[to][from] = min(cities[to][from], d[i][j]);
			}
		}
	}
	vector<edge> edges;
	F(i, total_cities) {
		for (int j = i + 1; j < total_cities; j += 1) {
			// printf("%lf\n", cities[i][j]);
			edges.push_back(edge(i, j, cities[i][j]));
		}
	}

	init_sets(nodes);
	double to_connect_all = kruskal(edges);

	printf("%d %d %d\n", total_cities, (int)round(total), (int)round(to_connect_all));
}

int main() {
	int cas;
	double x, y;
	cin >> cas;
	F(z, cas) {
		cin >> nodes >> r;
		reset();
		init_sets(nodes);
		F(i, nodes) {
			cin >> x >> y;
			P.push_back(Point(x, y));
		}
		printf("Case #%d: ", z + 1);
		solve();
	}
	return 0;
}