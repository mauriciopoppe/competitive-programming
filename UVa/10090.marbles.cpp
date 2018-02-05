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
	LL n;
	LL x, y;
	LL c1, n1;
	LL c2, n2;
	while (cin >> n && n) {
		cin >> c1 >> n1;
		cin >> c2 >> n2;

		vector<LL> ext = extended_euclidean(n1, n2);

		// first solution is scale * gcd(a, b) = a(sx) + b(sy)
		LL gcd = ext[0];
		LL scale = n / gcd;
		LL x1 = ext[1] * scale;
		LL y1 = ext[2] * scale;

		// bound check bounds
		LL k_lo = ceil(-1.0 * x1 * gcd / n2);
		LL k_hi = floor(1.0 * y1 * gcd / n1);

		if (n % gcd != 0 || k_lo > k_hi) {
			puts("failed");
			continue;
		}

		// cost = c1 * nbox1 + c2 * nbox2
		// cost = c1 * (x1 + n2 / gcd * k) + c2 * (y1 - n1 / gcd * k)
		// cost = c1 * x1 + c2 * y1 + k (c1 * n2 / gcd - c2 * n1 / gcd)
		// minimizing ks
		LL s = c1 * n2 / gcd - c2 * n1 / gcd;
		if (k_lo * s < k_hi * s) {
			x = x1 + n2 / gcd * k_lo;
			y = y1 - n1 / gcd * k_lo;
		} else {
			x = x1 + n2 / gcd * k_hi;
			y = y1 - n1 / gcd * k_hi;			
		}

		printf("%lld %lld\n", x, y);
	}
	return 0;
}