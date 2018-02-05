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

#define M 1000010
int p[M + 10], b[M + 10];
int dp[M + 10];
int tp;

void gen() {
	MS(dp, -1);
	MS(b, 0);
	for (int i = 3; i * i <= M; i += 2) {
		if (!b[i])
			for (int j = i * i; j <= M; j += 2 * i) {
				b[j] = 1;
			}
	}
	tp = 0;
	p[tp++] = 2;
	for (int i = 3; i <= M; i += 2) if (!b[i]) p[tp++] = i;
	for (int i = 0; i < tp; ++i) dp[p[i]] = 1;
}

int factorize(int n) {
	int sm = 0;
	for (int i = 0; p[i] * p[i] <= n; i += 1) {
		if(n % p[i] == 0) {
			sm += p[i];
			while (n % p[i] == 0) n /= p[i];
		}
	}
	if (n != 1) sm += n; 
	return sm;
}

map<int, vi> ans;

void add(int n, int k) {
	if (ans.find(k) == ans.end()) {
		ans[k] = vi();
	}
	ans[k].push_back(n);
}

int sm[M];
int ansdp[M][13];

void solveDP() {
	MS(sm, 0);
	for (int i = 2; i <= M; i += 2) sm[i] += 2;
	for (int i = 3; i + i <= M; i += 2) {
		if (!sm[i])
			for (int j = i; j <= M; j += i) {
				sm[j] += i;
			}
	}

	F(i, 13) ansdp[1][i] = 0;
	for (int i = 2; i <= M; i += 1) {
		// printf("%d: %d\n", i, sm[i]);
		F(j, 13) ansdp[i][j] = ansdp[i - 1][j];
		if (sm[i] == i || sm[i] == 0) dp[i] = 1;
		else dp[i] = dp[sm[i]] + 1;
		// add(i, dp[i]);
		++ansdp[i][dp[i]];
	}
}

int solve(int a, int b, int k) {
	if (ans.find(k) == ans.end()) return 0;
	vi &v = ans[k];
	vi::iterator low = lower_bound(v.begin(), v.end(), a);
	vi::iterator high = upper_bound(v.begin(), v.end(), b);

	if (low == v.end()) return 0;
	int l = low - v.begin(), h = high - v.begin();
	return h - l;
}

int main() {
	// gen();
	solveDP();

	int cas; cin >> cas;
	while (cas--) {
		int a, b, k;
		scanf("%d %d %d", &a, &b, &k);
		// printf("%d\n", solve(a, b, k));
		if (k > 12) {
			puts("0"); continue;
		}
		printf("%d\n", ansdp[b][k] - ansdp[a - 1][k]);
	}

	return 0;
}