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
 *
 * Computes
 *
 *    a^k % m
 *
 * @param {int} a
 * @param {int} k
 * @param {int} m
 * @return {int}
 */
LL binary_exponentiation_modulo_m(LL a, LL k, LL m) {
  if (k == 0) {
    return 1LL;
  }

  if (k % 2 == 1) {
    return (binary_exponentiation_modulo_m(a, k - 1, m) * a) % m;
  } else {
    // even power
    LL t = binary_exponentiation_modulo_m(a, k / 2, m);
    return (t * t) % m;
  }
}

int main() {
	LL a, k, m;
	while (cin >> a >> k >> m) {
		cout << binary_exponentiation_modulo_m(a, k, m) << endl;
	}
	return 0;
}