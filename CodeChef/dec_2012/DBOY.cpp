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
#define M 1050
int main() {
	// freopen("in", "r", stdin);
	// freopen("out", "w", stdout);
	
	int dp[M];
	int h[M], k[M];
	int n;
	int cas;
	cin >> cas;
	while (cas--) {
		cin >> n;
		F(i, n) cin >> h[i], h[i] *= 2;
		F(i, n) cin >> k[i];
		memset(dp, 63, sizeof dp);
		dp[0] = 0;
		F(i, M)
			F(j, n)
				if(i + k[j] < M)
					dp[i + k[j]] = min(dp[i + k[j]], dp[i] + 1);
		int total = 0;
		F(i, n) total += dp[h[i]];
		printf("%d\n", total);
	}
	return 0;
}