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

// 4 2
// 3

LL v[1000001];
LL n, p, q;
int solve(LL k) {
	LL d = k * q;
	F(i, n) {
		LL remaining = (v[i] - d);
		if (remaining > 0) {
			if (q != p)
				k -= (int) ceil((double)remaining / (double)(p - q));
			else
				return false;
		}
	}
	return k >= 0;
}

int main() {
	while (cin >> n >> p >> q) {
		F(i, n) cin >> v[i];
		LL low = 0, high = 1e9 * 2,
			best = -1;
		while (low <= high) {
			LL mid = (low + high) / 2;
			if (solve(mid)) {
				best = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		cout << best << endl;
	}
	return 0;
}