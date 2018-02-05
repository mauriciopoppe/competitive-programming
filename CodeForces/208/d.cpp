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

#define M 3004
int dp[M][2];
int a[M], b[M], c[M];
int n;
int solve(int p, int old) {
	if (p == n - 1)  {
		if (old == 0) return a[p];
		return b[p];
	}
	int p1, p2;
	int &res = dp[p][old];
	if (res == -1) {		
		if (old == 0) {
			// old not feed
			p1 = solve(p + 1, 1) + a[p];
			p2 = solve(p + 1, 0) + b[p];
		} else {
			p1 = solve(p + 1, 1) + b[p];
			p2 = solve(p + 1, 0) + c[p];
		}
		res = max(p1, p2);
	}
	return res;
}

int main() {
	while (cin >> n) {
		MS(dp, -1);
		F(i, n) cin >> a[i];
		F(i, n) cin >> b[i];
		F(i, n) cin >> c[i];
		printf("%d\n", solve(0, 0));
	}
	return 0;
}