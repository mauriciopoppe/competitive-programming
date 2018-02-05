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

#define M 27
bool awaken[M];
bool expanded[M];
int incoming[M];
bool g[M][M];
bool exists[M];
int nodes;

void reset() {
	memset(g, 0, sizeof g);
	memset(expanded, 0, sizeof expanded);
	memset(incoming, 0, sizeof incoming);
	memset(exists, 0, sizeof exists);
	memset(awaken, 0, sizeof awaken);
}

void read(int edges) {
	string awaked;
	cin >> awaked;
	F(i, awaked.size()) {
		awaken[awaked[i] - 'A'] = 1;
		exists[awaked[i] - 'A'] = 1;
	}

	string con;
	F(i, edges) {
		cin >> con;
		int from = con[0] - 'A';
		int to = con[1] - 'A';
		exists[from] = 1;
		exists[to] = 1;
		g[from][to] = g[to][from] = 1;
	}
}

int is_solved() {
	int total = 0;
	F(i, 26) {
		if (exists[i]) {
			if (!awaken[i])
				return false;
			++total;
		}
	}
	return total == nodes;
}

int solve() {
	int loops = 0;
	while (true) {
		if (is_solved()) break;
		int expanded_count = 0;
		F(i, 26) {
			if (awaken[i] && !expanded[i]) {
				// printf("%d\n", i);
				F(j, 26) {
					if (g[i][j]) {
						// printf("%c -> %c\n", i + 'A', j + 'A');
						incoming[j] += 1;
					}
				}
				expanded[i] = true;
				expanded_count += 1;
			}
		}
		F(i, 26) {
			// printf("%d [%d]\n", i, incoming[i]);
			if (!awaken[i] && incoming[i] >= 3) {
				awaken[i] = 1;
			}
		}
		++loops;
		if (expanded_count == 0) {
			break;
		}
	}
	return is_solved() ? loops : -1;
}

int main() {
	int edges;
	while (cin >> nodes >> edges) {
		reset();
		read(edges);
		int v = solve();
		if (v == -1) {
			printf("THIS BRAIN NEVER WAKES UP\n");
		} else {
			printf("WAKE UP IN, %d, YEARS\n", v);
		}
	}
	return 0;
}