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

#define M 1000101
#define MX (LL)1e13
LL p[M + 10];
bool b[M + 10];
int tp;

void gen() {
	MS(b, 0);
	for (int i = 3; i * i <= M; i += 2)
		if (!b[i])
			for (int j = i * i; j <= M; j += 2 * i)
				b[j] = 1;
	tp = 0;
	p[tp++] = 2;
	for (int i = 3; i <= M; i += 2)
		if (!b[i]) p[tp++] = i;
}

LL v[M], tv;

int isprime (int n) {
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	return !b[n];
}

void gen2() {
	tv = 0;
	for (int i = 0; i < tp; i += 1) {
		LL m = p[i];
		int cnt = 1;
		while (1) {
			m *= p[i];
			++cnt;
			if (m >= MX) break;
			if (isprime(cnt + 1)) {
				// if (m >= (LL)999999000000) printf("%lld^%d %lld\n", p[i], cnt, m);
				v[tv++] = m;
			}
		}
	}
	sort(v, v + tv);
}

int isp[M];
int find_primes(LL l, LL r) {
	MS(isp, 0);
	l = max(l, (LL)2);
	for (int i = 0; i < tp; i += 1) {
		LL j = l / p[i] * p[i];
		if (j < l) j += p[i];
		if (j - p[i] == 0) j += p[i];
		for (; j <= r; j += p[i]) {
			isp[j - l] = 1;
		}
	}
	int total = 0;
	for (int i = 0; i <= r - l; i += 1) {
		if (!isp[i]) ++total;
	}
	// printf("%d\n", total);
	return total;
}

int main() {
	gen();
	gen2();
	// puts("done");
	// F(i, 10) printf("%d\n", p[i]);

	LL l, r;
	int c;
	cin >> c;
	while (c--) {
		cin >> l >> r;
		int lb = lower_bound(v, v + tv, l) - v;
		int ub = upper_bound(v, v + tv, r) - v;
		// printf("%d\n", ub - lb);

		printf("%d\n", ub - lb + find_primes(l, r));
	}
	return 0;
}