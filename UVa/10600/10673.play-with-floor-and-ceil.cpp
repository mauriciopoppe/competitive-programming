#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define MS(a, v) memset(a, v, sizeof a)
#define NL printf("\n")
#define INF 1e9
#define PI acos(-1)
#define EPS 1e-9
#define TR(ar, it) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )

typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

/**
 * Computes the values x and y for the equation
 *
 *    ax + by = gcd(a, b)
 *
 * @returns {vector<int>} A triplet with the values (gcd(a, b), x, y)
 */
vector<LL> extended_euclidean(LL a, LL b) {
  if (b == 0) {
    // base case:
    // b divides a so a(1) + b(0) = a
    return vector<LL> {a, 1, 0};
  }
  vector<LL> t = extended_euclidean(b, a % b);
  LL gcd = t[0];
  LL x1 = t[1];
  LL y1 = t[2];
  return vector<LL> {gcd, y1, x1 - a / b * y1};
}

int main() {
	int n;
	cin >> n;
	LL x, k;
	for (int z = 0; z < n; z += 1) {
		if (z) puts("");
		cin >> x >> k;
		LL lo = floor((double) x / k);
		LL hi = ceil((double) x / k);
		vector<LL> ext = extended_euclidean(lo, hi);
		LL scale = x / ext[0];
		LL p = ext[1] * scale;
		LL q = ext[2] * scale;
		printf("%lld %lld", p, q);
	}
	return 0;
}