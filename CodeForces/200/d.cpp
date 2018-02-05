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
#define TR(ar, it) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define M 111
#define MATCH 0
#define LEFT 1
#define TOP 2

int dp[M][M][M], p[M][M];
int kmp[M];
int ci, cj, ck;

void failure(string virus) {
	int len = virus.size(), j;
	kmp[0] = j = -1;
	F(i, len) {
		while(j >= 0 && virus[i] != virus[j]) j = kmp[j];
		kmp[i + 1] = ++j;
	}
}

vi build(int i, int j) {
	vi pos;
	while(i >= 0 && j >= 0) {
		if (p[i][j] == MATCH) {
			pos.push_back(i);
			i--; j--;
		} else if (p[i][j] == TOP) i--;
		else j--;
	}
	reverse(ALL(pos));
	return pos;
}

void update(int i, int j, int k, int v, int parent) {
	if (v > dp[i][j][k]) {
		dp[i][j][k] = v;
		p[i][j] = parent;
	}
}

int main() {
	string a, b, virus;
	while (cin >> a >> b >> virus) {
		int la = a.size();
		int lb = b.size();
		int lv = virus.size();
		failure(virus);
		// F(i, lv + 1) printf("%d ", kmp[i]); NL;

		MS(dp, -1);
		dp[0][0][0] = 0;
		for(int i = 0; i < la; i += 1) {
			for(int j = 0; j < lb; j += 1) {
				F(k, lv) {
					if (dp[i][j][k] > -1) {
						int v = dp[i][j][k];
						update(i + 1, j, k, v, LEFT);
						update(i, j + 1, k, v, TOP);
						if (a[i] == b[j]) {
							int longest = k;
							while (longest >= 0 && virus[longest] != a[i]) longest = kmp[longest];
							longest += 1;
							update(i + 1, j + 1, longest, v + 1, MATCH);
						}
					}
				}
			}
		} 

		int mx = 0;
		F(k, lv) mx = max(mx, dp[la][lb][k]);
		if (mx == 0) puts("0");
		else {
			vi path = build(la, lb);
			F(i, path.size()) {
				cout << a[path[i]];
			}NL;	
		}
	}
	return 0;
}