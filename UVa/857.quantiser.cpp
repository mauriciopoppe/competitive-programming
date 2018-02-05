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

int ticks[] = {0, 60, 120, 180, 240, 300, 360, 420, 480};

int solve(int t) {
	int mn = INF, index;
	F(i, 9) {
		if (abs(t - ticks[i]) <= mn) {
			mn = abs(t - ticks[i]);
			index = i;
		}
	}
	if (index == 8) return -1;
	return index;
}

bool equals(vi &a, vi &b) {
	FOR(i, 1, 5) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

int main() {
	int n;
	while (cin >> n && n != -1) {
		vector<vi> v;
		F(i, n) {
			vi entry(5);
			F(j, 5) cin >> entry[j];
			v.push_back(entry);
		}

		F(i, n) {
			int fixed = solve(v[i][4]);
			if (fixed != -1) {
				v[i][4] = ticks[fixed];
			} else {
				v[i][4] = 0;
				v[i][3] += 1;
				if (v[i][3] == 5) {
					v[i][3] = 1;
					v[i][2] += 1;
				}
			}
			// printf("%d %d %d %d\n", v[i][1], v[i][2], v[i][3], v[i][4]);
		}

		map<int, int> m;
		vector<int> avoid(n, 0);
		int avoided = 0;
		F(i, n) {
			if (v[i][0]) {
				m[v[i][1]] = i;
			} else {
				int old = m[v[i][1]],
					cur = i;
				if (equals(v[old], v[cur])) {
					avoided += 2;
					avoid[old] = 1;
					avoid[cur] = 1;
				}
				m[v[i][1]] = -1;
			}
		}

		printf("%d\n", n - avoided);
		F(i, n) {
			if (!avoid[i]) {
				F(j, 5) {
					if (j) printf(" ");
					printf("%d", v[i][j]);
				}
				NL;
			}
		}
	}
	puts("-1");
	return 0;
}