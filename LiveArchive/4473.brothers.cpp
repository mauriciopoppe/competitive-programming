#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <sstream>
#include <utility>
#include <numeric>
#include <functional>
using namespace std;
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define X first
#define Y second
#define MS(a, v) memset(a, v, sizeof a)
#define NL printf("\n")
#define SP system("pause")
#define INF 1e9
#define PI acos(-1)
#define EPS 1e-9
#define TR(ar, it) for ( decltype(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

int m[2][105][105];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
int row, col;

int isValid(int x, int y) {
	return x >= 0 && y >= 0 && x < row && y < col;
}

int print(int c) {
	F(i, row) {
		F(j, col) {
			if (j) putchar(' ');
			printf("%d", m[c][i][j]);
		}
		NL;
	}
}

int main() {
	int n, k;
	while (cin >> n >> row >> col >> k && n + row + col + k != 0) {
		int cur = 0, next = 1 - cur;
		F(i, row) F(j, col) scanf("%d", &m[cur][i][j]);

		F(z, k) {
			memcpy(m[next], m[cur], sizeof m[cur]);
			// print(next);
			F(i, row)
				F(j, col) {
					F(k, 4) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (isValid(nx, ny)) {
							int kingdom = m[cur][i][j];
							int toAttack = m[cur][nx][ny];
							if ((kingdom + 1) % n == toAttack) {
								// printf("%d %d -> %d %d\n", i, j, nx, ny);
								// printf("> %d %d\n", kingdom, toAttack);
								m[next][nx][ny] = kingdom;
							}
						}
					}
				}
			// printf("--After %d\n", z + 1);
			// print(next);
			next = cur;
			cur = 1 - cur;
		}
		print(cur);
	}
	return 0;
}