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

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

char m[101][101];
int row, col;
int cx, cy;
int string_length;
int total;
int dir;
string path;

int valid(int x, int y) {
	return x >= 0 && x < row && y >= 0 & y < col;
}

void move() {
	int nx = cx + dx[dir];
	int ny = cy + dy[dir];
	if (valid(nx, ny) && m[nx][ny] != '#') {
		cx = nx;
		cy = ny;
		if (m[cx][cy] == '*') {
			total += 1;
			m[cx][cy] = '.';
		}
	}
}

void rotate(int d) {
	dir += d;
	dir += 4;
	dir %= 4;
}

int main() {
	while (cin >> row >> col >> string_length) {
		if (row == 0 && col == 0 && string_length == 0) {
			break;
		}
		getline(cin, path);
		F(i, row) {
			gets(m[i]);
			F(j, col) {
				if (m[i][j] != '#' && m[i][j] != '.' && m[i][j] != '*') {
					cx = i;
					cy = j;
				}
				if (m[i][j] == 'N') dir = 0;
				if (m[i][j] == 'L') dir = 1;
				if (m[i][j] == 'S') dir = 2;
				if (m[i][j] == 'O') dir = 3;
			}
		}
		getline(cin, path);
		total = 0;
		for (int i = 0; i < string_length; i += 1) {
			if (path[i] == 'D') rotate(1);
			if (path[i] == 'E') rotate(-1);
			if (path[i] == 'F') {
				move();
			}
		}
		printf("%d\n", total);
	}
	return 0;
}