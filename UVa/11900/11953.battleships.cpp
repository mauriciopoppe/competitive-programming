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
char m[M][M];
int visited[M][M];
int n;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int valid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

void dfs(int x, int y, map<char, int> &mp) {
	// printf("%d %d\n", x, y);
	visited[x][y] = true;
	mp[ m[x][y] ]++;
	F(i, 4) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (valid(nx, ny) && m[nx][ny] != '.' &&
			!visited[nx][ny]) {
			dfs(nx, ny, mp);
		}
	}
}

int solve(int x, int y) {
	map<char, int> mp;
	dfs(x, y, mp);
	return mp['x'] > 0;
}

int main() {
	int cas;
	cin >> cas;
	F(z, cas) {
		cin >> n;
		gets(m[0]);
		F(i, n) gets(m[i]);

		memset(visited, 0, sizeof visited);
		int total = 0;
		F(i, n) {
			F(j, n) {
				if (m[i][j] != '.' && !visited[i][j]) {
					total += solve(i, j);
				}
			}
		}
		printf("Case %d: %d\n", z + 1, total);
	}
	return 0;
}