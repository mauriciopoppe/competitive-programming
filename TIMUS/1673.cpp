// TLE, solution involves inverse phi computation
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

#define M 45000

bool sieve[M];

int n_primes;
int primes[M];

bool is_prime(int n) {
	for (int i = 0; i < n_primes; i += 1) {
		if (n % sieve[i] == 0) {
			return false;
		}
	}
	return true;
}

int phi(int n) {
  int result = n;
  for (int i = 2; i * i <= n; i += 1) {
    // if `i` is a divisor of `n`
    if (n % i == 0) {
      // divide it by `i^k` so that it's no longer divisible by `i`
      while (n % i == 0) {
        n /= i;
      }
      // all the multiples of `i` are coprime to n, the number of
      // multiples is equal to `i * k` <= n, therefore `k <= n / i`
      result -= result / i;
    }
  }
  if (n > 1) {
    result -= result / n;
  }
  return result;
}

void calc_sieve() {
	memset(sieve, 0, sizeof sieve);
	for (int i = 2; i < M; i += 1) {
		sieve[i] = true;
	}
	for (int i = 3; i * i < M; i += 2) {
		if (!sieve[i]) {
			for (int j = i; j < M; j += 2 * i) {
				sieve[j] = true;
			}			
		}
	}
	n_primes = 0;
	primes[n_primes++] = 2;
	for (int i = 3; i < M; i += 1) {
		if (!sieve[i]) {
			primes[n_primes++] = i;
		}
	}
}

int main() {
	calc_sieve();

	int n;
	while (cin >> n) {
		if (n == 1) {
			printf("1\n");
			continue;
		}

		if (n % 2 == 1) {
			printf("0\n");
			continue;
		}

		int res;
		for (int i = n; ; i += 1) {
			if (phi(i) == n) {
				res = i;
				break;
			}
		}
		cout << res << endl;
	}
	return 0;
}