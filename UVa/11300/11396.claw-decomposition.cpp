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

#define M 305

int nodes;

int color[M];
bool g[M][M];

bool is_bicolorable() {
	queue<int> q;
	q.push(0);
	color[0] = 0;
	while (!q.empty()) {
		int top = q.front();
		int top_color = color[top];
		int new_color = 1 - color[top];
		q.pop();
		F(i, M) {
			if (g[top][i]) {
				if (color[i] == -1) {
					q.push(i);
					color[i] = new_color;
				} else if (color[i] != new_color) {
					return false;
				}
			}
		}
	}
	return true;
}

void reset() {
	memset(color, -1, sizeof color);
	memset(g, 0, sizeof g);
}

void read() {
	int from, to;
	while (cin >> from >> to && from != 0) {
		--from;
		--to;
		g[from][to] = g[to][from] = 1;
	}
}

int main() {
	while (cin >> nodes && nodes) {
		reset();
		read();
		printf("%s\n", is_bicolorable() ? "YES" : "NO");
	}
	return 0;
}