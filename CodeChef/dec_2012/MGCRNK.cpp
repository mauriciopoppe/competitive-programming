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
#define M 105
int m[M][M], dp[M][M];
int main() {
	// freopen("in", "r", stdin);
	// freopen("out", "w", stdout);
	
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		F(i, n) F(j, n) cin >> m[i][j], dp[i][j] = -999999999;
		dp[0][0] = 0;
		F(i, n)
			F(j, n)
				dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + m[i][j + 1]),
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + m[i + 1][j]);
		if (dp[n - 1][n - 1] < 0) puts("Bad Judges");
		else printf("%.6lf\n", (double) dp[n - 1][n - 1] / (double) (n - 1 + n - 2));
	}
	return 0;
}