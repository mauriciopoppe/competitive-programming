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
typedef unsigned long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 1e9 + 7;

LL bin_pow(LL b, LL p) {
	LL ans = 1, base = b;
	while (p) {
		if (p & 1) {
			ans = (ans * base) % MOD;
		}
		p >>= 1;
		base = (base * base) % MOD;
	}
	return ans;
}

int bin[1234];
LL make_bin(LL n) {
	int top = 0;
	while (n) {
		bin[top++] = n % 2;
		n >>= 1;
	}

	LL ans = 0;
	for (int i = top - 1; i >= 0; i -= 1) {
		ans += bin[i];
		if (i) ans *= 10;
	}
	return ans;
}

int main() {
	int t;
	LL n;
	cin >> t;
	while (t--) {
		scanf("%llu", &n);
		LL ans = bin_pow(2, make_bin(n));
		ans = bin_pow(ans, 2);
		printf("%llu\n", ans);
	}
	return 0;
}