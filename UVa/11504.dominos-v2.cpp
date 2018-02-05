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

#define M 100003
// graph
int nodes, edges;
vector<vi> g;
vector<vi> h;

// scc
int node_index;
int scc_count;
stack<int> vertices;
int in_stack[M];
int dfs_order[M];
int low_link[M];
int scc[M];

void read_graph() {
	g.clear();
	g.resize(nodes, vi());

	int from, to;
	F(i, edges) {
		cin >> from >> to;
		g[--from].push_back(--to);
	}

	// low index is not resetted because it'll
	// be done on the scc method
	memset(dfs_order, -1, sizeof dfs_order);
	memset(in_stack, 0, sizeof in_stack);
	memset(scc, 0, sizeof scc);
	node_index = 0;
	scc_count = 0;
}

void tarjan_scc(int v) {
	dfs_order[v] = node_index;
	low_link[v] = node_index;
	node_index += 1;
	in_stack[v] = true;
	vertices.push(v);

	TR(g[v], it) {
		if (dfs_order[*it] == -1) {
			tarjan_scc(*it);
			low_link[v] = min(low_link[v], low_link[*it]);
		} else if (in_stack[*it]) {
			low_link[v] = min(low_link[v], dfs_order[*it]);
		}
	}

	// recover the nodes
	if (low_link[v] == dfs_order[v]) {
		// printf("> %d\n", v);
		int top;
		do {
			top = vertices.top();
			vertices.pop();
			scc[top] = scc_count;
			in_stack[top] = false;
		} while(top != v);
		scc_count += 1;
	}
}

bool vh[M];
void topological_sort(int n, stack<int> &s) {
	vh[n] = true;
	F(i, h[n].size()) {
		if (!vh[ h[n][i] ]) {
			topological_sort(h[n][i], s);
		}
	}
	s.push(n);
}

int dfs_h(int n) {
	vh[n] = true;
	F(i, h[n].size()) {
		int next = h[n][i];
		if (!vh[next]) {
			dfs_h(next);
		}
	}
}

int solve() {
	h.clear();
	h.resize(scc_count);

	map<pii, bool> link;
	F(i, g.size()) {
		F(j, g[i].size()) {
			int from = scc[i];
			int to = scc[g[i][j]];
			if(link.find(pii(from, to)) == link.end()) {
				h[from].push_back(to);
				link[pii(from, to)] = true;
			}
		}
	}
	stack<int> s;
	memset(vh, 0, sizeof vh);
	F(i, h.size()) {
		topological_sort(i, s);
	}
	memset(vh, 0, sizeof vh);

	int total = 0;
	while(!s.empty()) {
		int top = s.top();
		s.pop();
		if (!vh[top]) {
			++total;
			dfs_h(top);
		}
	}
	return total;
}

int main() {
	int cas;
	cin >> cas;
	while(cas--) {
		cin >> nodes >> edges;
		read_graph();
		F(i, nodes) {
			if (dfs_order[i] == -1) {
				// printf("scc in %d\n", i);
				tarjan_scc(i);
			}
		}
		printf("%d\n", solve());
	}
	return 0;
}