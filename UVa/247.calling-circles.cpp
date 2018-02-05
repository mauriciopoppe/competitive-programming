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

#define M 30
int nodes, edges;
vector<vi> g;

int node_index;
int scc_count;
stack<int> vertices;
int in_stack[M];
int dfs_order[M];
int low_link[M];
int scc[M];
map<int, string> reverse_name;

void read_graph() {
	int index = 0;
	map<string, int> hash;
	string from, to;
	g.clear();
	reverse_name.clear();
	g.resize(nodes, vi());

	F(i, edges) {
		cin >> from >> to;
		if (hash.find(from) == hash.end()) {
			hash[from] = index++;
			reverse_name[index - 1] = from;
		}
		if (hash.find(to) == hash.end()) {
			hash[to] = index++;
			reverse_name[index - 1] = to;
		}
		g[hash[from]].push_back(hash[to]);
	}

	// F(i, nodes) {
	// 	printf("%d: ", i);
	// 	TR(g[i], it) printf("-> %d ", *it);
	// 	NL;
	// }

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

int main() {
	int cas = 0;
	while(cin >> nodes >> edges) {
		if (nodes + edges == 0)break;
		if (cas) NL;
		read_graph();
		F(i, nodes) {
			if (dfs_order[i] == -1) {
				// printf("scc in %d\n", i);
				tarjan_scc(i);
			}
		}
		vector<vector<string> > names(scc_count, vector<string>());
		F(i, nodes) {
			names[scc[i]].push_back(reverse_name[i]);
		}
		printf("Calling circles for data set %d:\n", ++cas);
		F(i, scc_count) {
			F(j, names[i].size()) {
				if (j) printf(", ");
				printf("%s", names[i][j].c_str());
			}
			NL;
		}
	}
	return 0;
}