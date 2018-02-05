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

#define M 10000
int dp[M + M];
int v[10];

void solve() {
	fill(dp, dp + M, INF);
	dp[0] = 0;
	for (int i = 0; i <= M; i += 1) {
		for (int j = 0; j < 6; j += 1) {
			dp[i + v[j]] = min(dp[i + v[j]], dp[i] + 1);
		}
	}
}


int main() {
	int n;
	cin >> n;
	while (n--) {
		F(i, 6) cin >> v[i];
		solve();
		
		int total = 0,
			mx = 0;
		for (int i = 1; i <= 100; i += 1) {
			int best = dp[i];
			for (int j = i + 1; j <= M; j += 1) {
				if (dp[j] != INF && dp[j - i] != INF) {
					best = min(best, dp[j] + dp[j - i]);
				}
			}
			// printf("%d - %d\n", i, best);
			total += best;
			mx = max(mx, best);			
		}
		printf("%.2lf %d\n", (double) total / (double) 100, mx);
	}
	return 0;
}