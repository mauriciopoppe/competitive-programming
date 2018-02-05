#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define MS(a, v) memset(a, v, sizeof a)
#define NL printf("\n")
#define INF 1e9
#define PI acos(-1)
#define EPS 1e-9
#define TR(ar, it) for ( decltype(ar.begin()) it = ar.begin(); it != ar.end(); it++ )

typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

LL binary_exponentiation_modulo_m(LL a, LL k, LL m) {
  if (k == 0) {
    return 1LL;
  }
  if (k % 2 == 1) {
    return (binary_exponentiation_modulo_m(a, k - 1, m) * a) % m;
  } else {
    LL t = binary_exponentiation_modulo_m(a, k / 2, m);
    return (t * t) % m;
  }
}

/**
 * Computes the values `x` and `y` for the equation
 *
 *    ax + by = gcd(a, b)
 *
 * Given that `a` and `b` are positive integers
 *
 * @param {int} a
 * @param {int} b
 * @param {int} x
 * @param {int} y
 * @returns {int} gcd(a, b)
 */
LL extended_euclidean(LL a, LL b, LL &x, LL &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  LL x1, y1;
  LL gcd = extended_euclidean(b, a % b, x1, y1);
  x = y1;
  y = x1 - a / b * y1;
  return gcd;
}

/**
 * Computes the modular mutiplicative inverse of the number `a` in the ring
 * of integers modulo `m`
 *
 *    ax ≡ 1 (mod m)
 *
 * `x` only exists if `a` and `m` are coprimes
 *
 * @param {int} a
 * @param {int} m
 * @param {int} x
 * @returns {bool} True if the number `a` has a modular multiplicative
 * inverse, false otherwise
 */
bool modular_multiplicative_inverse(LL a, LL m, LL &x) {
  // the value multiplying `y` is never used
  LL y;
  LL gcd = extended_euclidean(a, m, x, y);
  if (gcd != 1) {
    // `a` and `m` are not coprime
    return false;
  }
  // ensure that the value of `x` is positive
  x = (x % m + m) % m;
  return true;
}

/**
 * Let `a`, `b` and `n` be **integers**, where `a` and `n` are coprime,
 * the following is an implementation of Shank's baby step giant step
 * algorithm which attempts to find a solution for the congruence
 *
 *    a^x ≡ b (mod n)
 *
 * `x` can be represented as `im + j` then
 *
 *   a^j ≡ b(a^{-m})^i (mod m)
 *
 * NOTE: `binary_exponentiation_modulo_m` is a function which computes
 *
 *    a^x (mod m)
 *
 * @param {int} a
 * @param {int} b
 * @param {int} m
 * @returns {int} An integer >= 0 which is the value of `x`, -1
 * if no value was found
 */
LL baby_step_giant_step(LL a, LL b, LL n) {
  LL m = ceil(sqrt(n));

  // values in the left side
  map<LL, LL> M;

  // store all possible a^j
  LL aj = 1;
  for (int i = 0; i < m; i += 1) {
    if (!M.count(aj)) {
      M[aj] = i;
    }
    aj = (aj * a) % n;
  }

  // compute b(a^{-m})^i
  // first compute the modular multiplicative inverse of a
  LL inverse;
  if (!modular_multiplicative_inverse(a, n, inverse)) {
    return -1;
  }
  // compute inverse^m % n
  LL coef = binary_exponentiation_modulo_m(inverse, m, n);

  LL gamma = b;
  for (int i = 0; i < m; i += 1) {
    if (M.count(gamma)) {
      return (LL)i * m + M[gamma];
    }
    gamma = (gamma * coef) % n;
  }
  return -1;
}

int main() {
	int n;
	int a, b;
	cin >> n;
	F(z, n) {
		cin >> a >> b;
		printf("Case %d: %lld\n", z + 1, baby_step_giant_step(a, b, 100000007));
	}
	return 0;
}