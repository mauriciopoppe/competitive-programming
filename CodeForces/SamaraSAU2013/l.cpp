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

#define M 1000005
int dp[M + 10];
map<int, int> dpm;

int memo(int n) {
	return n < M ? dp[n] : dpm[n];
}
// 123 123 123 123

int solve(int n) {
	int mn = memo(n);
	if (mn > 0) return mn;

	int best = n / 2 + 1;
	// printf(">> %d best=%d\n", n, best);
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			int a = n / i;
			int b = i;
			// printf("groups %d %d\n", n / i, i);
			int ma = memo(a);
			int mb = memo(b);
			best = min(best,
				(ma > 0 ? ma : solve(a)) *
				(mb > 0 ? mb : solve(b))
			);
			// printf("%d=%d %d=%d\n", a, memo(a), b, memo(b));
		}
	}
	// printf("sol for %d = %d\n", n, best);
	if (n < M) dp[n] = best;
	else dpm[n] = best;
	return best;
}

int main() {
	int n;
	MS(dp, -1);
	dp[1] = 1;
	while (cin >> n) {		
		cout << solve(n) << endl;
	}
	return 0;
}