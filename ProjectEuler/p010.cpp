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

// C++11
#include <random>

LL binary_exponentiation_modulo_m(LL a, LL k, LL m) {
  if (k == 0) {
    // a^0 = 1
    return 1;
  }

  if (k % 2 == 1) {
    return (binary_exponentiation_modulo_m(a, k - 1, m) * a) % m;
  } else {
    LL t = binary_exponentiation_modulo_m(a, k / 2, m);
    return (t * t) % m;
  }
}

bool miller_rabin_primality_test(long long a, long long n) {
  int s = 0;
  long long q = n - 1;
  while (q % 2 == 0) {
    q /= 2;
    s += 1;
  }
  long long m = binary_exponentiation_modulo_m(a, q, n);
  if (m == 1 || m == n - 1) {
    // base case a^q ≡ 1 (mod n)
    return true;
  }
  for (int i = 0; i < s; i += 1) {
    // a^{2^iq} (mod n)
    m = (m * m) % n;
    if (m == n - 1) {
      return true;
    }
  }
  return false;
}

bool is_probably_prime(long long p, int iterations) {
	// NOTE: test of the primes 2 and 3 because of
	// the distribution limits (2, p - 2)
  if (p == 2 || p == 3) {
    return true;
  }
  if (p % 2 == 0 || p == 1) {
    return false;
  }
  std::random_device rd;
  std::mt19937 engine(rd());
  std::uniform_int_distribution<long long> dis(2, p - 2);
  while (iterations--) {
    // choose an integer between 2 and n-2
    long long a = dis(engine);
    if (!miller_rabin_primality_test(a, p)) {
      return false;
    }
  }
  return true;
}

int main() {
	LL sum = 2;
	for (LL i = 3; i < 2000000; i += 2) {
		if (is_probably_prime(i, 20)) {
			sum += i;
		}
	}
	cout << sum << endl;
	return 0;
}