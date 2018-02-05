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

#define M (LL)(1e9+7)
LL big_mod(LL b, LL p) {
	LL ans = 1;
	while (p) {
		if (p & 1) ans = (ans * b) % M;
		b = (b * b) % M;
		p >>= 1;
	}
	return ans;
}

int main() {
	int cas, n;
	cin >> cas;
	while (cas--) {
		scanf("%d", &n);
		LL res = big_mod(2LL, (LL)n) - 1;
		if (res < 0) res += M;
		printf("%lld\n", res);
	}
	return 0;
}