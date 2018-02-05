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

// int dx[] = {-1, -1, 1, 1};
// int dy[] = {-1, 1, -1, 1};

int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

#define M 110
int visited[M][M];
int marked[M][M];
bool forbidden[M][M];
int row, col;
int jx, jy;

int valid(int x, int y) {
	return x >= 0 && x < row && y >= 0 && y < col &&
		!forbidden[x][y];
}

void dfs(int x, int y) {
	// printf("> %d %d\n", x, y);
	if (visited[x][y]) {
		return;
	}
	visited[x][y] = 1;
	int jumps = 0;

	map<pii, bool> mp;
	for (int i = 0; i < 8; i += 1) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (valid(nx, ny) && mp.find(pii(nx, ny)) == mp.end()) {
			// printf("%d %d\n", nx, ny);
			mp[pii(nx, ny)] = true;
			jumps += 1;
		}
	}
	jumps %= 2;
	marked[x][y] = jumps;
	// printf("jumps: %d\n", jumps);

	for (int i = 0; i < 8; i += 1) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (valid(nx, ny) && !visited[nx][ny]) {
			dfs(nx, ny);
		}
	}
}

int fix(int jx, int jy) {
	dx[0] = -jx;
	dx[1] = -jy;
	dx[2] = jy;
	dx[3] = jx;
	dx[4] = -jx;
	dx[5] = -jy;
	dx[6] = jy;
	dx[7] = jx;

	dy[0] = -jy;
	dy[1] = -jx;
	dy[2] = -jx;
	dy[3] = -jy;
	dy[4] = jy;
	dy[5] = jx;
	dy[6] = jx;
	dy[7] = jy;
}

int main() {
	int t;
	cin >> t;
	F(z, t) {
		memset(forbidden, 0, sizeof forbidden);
		memset(marked, -1, sizeof marked);
		memset(visited, 0, sizeof visited);

		cin >> row >> col >> jx >> jy;
		fix(jx, jy);

		int f, x, y;
		cin >> f;
		F(i, f) {
			cin >> x >> y;
			forbidden[x][y] = 1;
		}

		dfs(0, 0);
		int even = 0, odd = 0;
		F(i, row) {
			F(j, col) {
				if (marked[i][j] == 1) odd += 1;
				else if (marked[i][j] == 0) even += 1;
				// printf("%d ", marked[i][j]);
			}
			// NL;
		}
		printf("Case %d: %d %d\n", z + 1, even, odd);
	}
	return 0;
}