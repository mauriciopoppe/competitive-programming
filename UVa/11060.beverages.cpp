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

#define M 110
bool g[M][M];
int indeg[M];
int visited[M];
map<string, int> names;
map<int, string> names_rev;

int nodes, edges;
int cas;

class Comparison {
public:
	bool operator() (pii &a, pii &b) {
		if (a.second != b.second) return a.second > b.second;
		return a.first > b.first;
	}
};

// pii(level, index)
priority_queue<pii, vector<pii>, Comparison> pq;

void reset() {
	memset(g, 0, sizeof g);
	memset(indeg, 0, sizeof indeg);
	memset(visited, 0, sizeof visited);
	names.clear();
	names_rev.clear();
	pq = priority_queue<pii, vector<pii>, Comparison>();
}

void read() {
	string s;
	int index = 0;
	F(i, nodes) {
		cin >> s;
		names[s] = index;
		names_rev[index] = s;
		++index;
	}

	cin >> edges;
	string from, to;
	F(i, edges) {
		cin >> from >> to;
		if (!g[names[from]][names[to]]) {
			g[names[from]][names[to]] = 1;
			indeg[names[to]]++;
		}
	}
	// printf("END\n");

	F(i, nodes) {
		if (!indeg[i]) {
			pq.push(pii(0, i));
		}
	}
}

void solve() {
	printf("Case #%d: Dilbert should drink beverages in this order:", ++cas);
	while (!pq.empty()) {
		pii top = pq.top();
		pq.pop();
		printf(" %s", names_rev[top.second].c_str());
		// printf(" lev=%d ind=%d\n", top.first, top.second);
		F(i, M) {
			if (g[top.second][i] && !--indeg[i]) {
				pq.push(pii(top.first + 1, i));
			}
		}
	}
	printf(".\n\n");
}

int main() {
	cas = 0;
	while (cin >> nodes) {
		reset();
		read();
		solve();
	}
	return 0;
}