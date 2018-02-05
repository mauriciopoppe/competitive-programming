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

int n, m;
vi vn(100);
vi vm(100);

int solve(int k) {
	int extra = 0;
	F(i, n) {
		if (k < vn[i]) return 0;
		if (k >= vn[i] * 2) extra++;
	}

	F(i, m) {
		if (k >= vm[i]) return 0;
	}
	return extra;
}

int main() {
	while (cin >> n >> m) {
		F(i, n) cin >> vn[i];
		F(i, m) cin >> vm[i];

		int k = 1;
		for(; k <= 100; k += 1) {
			if (solve(k)) {
				printf("%d\n", k);
				break;
			}
		}
		if (k > 100) puts("-1");
	}
	return 0;
}