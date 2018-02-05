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
#define M 2005

vector<vi> g;

// scc
int scc_index;
int scc_total;
int dfs_order[M];
int low_index[M];
bool in_stack[M];
stack<int> scc_path;

int nodes, edges;

void tarjan_scc(int v) {
	dfs_order[v] = low_index[v] = scc_index++;
	in_stack[v] = true;
	scc_path.push(v);

	TR(g[v], it) {
		int next = *it;
		if (dfs_order[next] == -1) {
			tarjan_scc(next);
			low_index[v] = min(low_index[v], low_index[next]);
		} else if (in_stack[next]) {
			low_index[v] = min(low_index[v], dfs_order[next]);
		}
	}

	if (dfs_order[v] == low_index[v]) {
		scc_total += 1;
		int top;
		do {
			top = scc_path.top();
			scc_path.pop();
			in_stack[top] = false;
		} while (top != v);
	}
}

void reset() {
	g.clear();
	scc_path = stack<int>();
	memset(dfs_order, -1, sizeof dfs_order);
	memset(in_stack, false, sizeof in_stack);
	scc_total = scc_index = 0;
}

void read() {
	int from, to, type;
	g.resize(nodes, vi());
	F(i, edges) {
		cin >> from >> to >> type;
		--from; --to;
		g[from].push_back(to);
		if (type == 2) {
			g[to].push_back(from);
		}
	}
}

void solve() {
	F(i, nodes) {
		if (dfs_order[i] == -1) {
			tarjan_scc(i);
		}
	}
}

int main() {
	while (cin >> nodes >> edges && nodes + edges != 0) {
		reset();
		read();
		solve();
		if (scc_total == 1) {
			puts("1");
		} else {
			puts("0");
		}
	}
	return 0;
}