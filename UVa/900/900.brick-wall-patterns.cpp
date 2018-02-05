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

LL dp[55];

LL solve(int n) {
	if (dp[n] == -1) {
		dp[n] = solve(n - 1) + solve(n - 2);
	}
	return dp[n];
}

int main() {
	memset(dp, -1, sizeof dp);
	dp[0] = 1;
	dp[1] = 1;
	int n;
	while (cin >> n && n) {
		cout << solve(n) << endl;
	}
	return 0;
}