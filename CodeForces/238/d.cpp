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

#define M 1000006
int dp[M];
int p[M];
int inv[M];

int main() {
	int n, k;
	while (cin >> n) {
		MS(inv, 0);
		MS(dp, 0);
		MS(p, -1);
		int sm = 0;
		F(i, n) cin >> k, inv[k] = 1, sm += k - 1;

		for (int i = 0; i <= sm; i += 1) {
			if (!inv[i]) {
				dp[i] = 1;
				p[i] = INF;
				break;
			}
		}
		for (int i = sm; i >= 0; i--) {
			if (!inv[i]) {
				for (int j = sm; j - i >= 0; j--) {
					if (dp[j - i] && p[j] == -1) {
						p[j] = j - i;
						// printf("%d %d\n", j, p[j]);
						dp[j] = 1;
					}
				}
			}
		}
		int total;
		vector<int> sol;
		// puts("end");
		while (true) {
			sol.push_back(sm);
			sm = p[sm];
			if (sm == INF) break;
		}
		// sol.push_back(sm);
		printf("%d\n", (int)sol.size());
		for (int i = 0, size = sol.size(); i < size; i += 1) {
			printf("%d ", 1000000 - sol[i]);
		}
		NL;
	}
	return 0;
}