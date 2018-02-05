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

#define M 50010
int node_index;
int dfs_order[M], low_link[M];
bool in_stack[M];
int dp[M];

stack<int> st;
vector<vi> g;

int nodes, edges;

void tarjan_scc(int v) {
	dfs_order[v] = low_link[v] = node_index++;
	in_stack[v] = true;
	st.push(v);

	F(i, g[v].size()) {
		int next = g[v][i];
		if (dfs_order[next] == -1) {
			tarjan_scc(next);
			low_link[v] = min(low_link[v], low_link[next]);
		} else if (in_stack[next]) {
			low_link[v] = min(low_link[v], dfs_order[next]);
		}
	}

	if (dfs_order[v] == low_link[v]) {
		int top;
		int cnt = 0;
		vector<int> cycle;
		do {
			top = st.top();
			st.pop();
			in_stack[top] = false;
			cycle.push_back(top);
			++cnt;
		} while (top != v);
		if (cnt > 1) {
			TR(cycle, it) {
				dp[*it] = cnt;
			}
		}
	}
}

int dfs_dp(int v) {
	// printf("dp %d\n", v);
	if (dp[v] != -1) return dp[v];
	int total = 1;
	F(i, g[v].size()) {
		int next = g[v][i];
		if (next != v) {
			total += dfs_dp(next);
		}
	}
	return (dp[v] = total);
}

int solve() {
	memset(dfs_order, -1, sizeof dfs_order);
	memset(in_stack, 0, sizeof in_stack);
	memset(dp, -1, sizeof dp);
	node_index = 0;

	st = stack<int>();
	F(i, nodes) {
		if (dfs_order[i] == -1) {
			tarjan_scc(i);
		}
	}
	// F(i, nodes) {
	// 	printf("%d ", dp[i]);
	// }
	// NL;

	int mx = 0, best = -1;
	F(i, nodes) {
		if (dp[i] == -1) {
			// printf("(%d)\n", i);
			dfs_dp(i);
		}
		if (dp[i] > mx) {
			// printf("%d %d\n", i, dp[i]);
			mx = dp[i];
			best = i;
		}
	}
	return best;
}

void read_graph() {
	int from, to;
	g.clear();
	g.resize(M, vi());
	F(i, nodes) {
		cin >> from >> to;
		g[--from].push_back(--to);
	}
}

int main() {
	int cas;
	cin >> cas;
	F(z, cas) {
		cin >> nodes;
		read_graph();
		printf("Case %d: %d\n", z + 1, solve() + 1);
	}
	return 0;
}