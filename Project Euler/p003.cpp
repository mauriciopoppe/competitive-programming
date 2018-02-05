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

void prime_factors(LL n) {
	for (LL i = 2; i * i <= n; i += 1) {
		if (n % i == 0) {
			cout << i << endl;
		}
		while (n % i == 0) n /= i;
	}
	if (n > 1) {
		cout << n << endl;
	}
}

int main() {
	prime_factors(600851475143LL);
	return 0;
}