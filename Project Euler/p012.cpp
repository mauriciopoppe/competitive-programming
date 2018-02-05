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

int n_divisors(LL n) {
	int total = 2;
	for (LL i = 2; i * i <= n; i += 1) {
		if (n % i == 0) {
			LL other = n / i;
			total += 2;
			if (other == i) {
				total -= 1;
			}
		}
	}
	return total;
}

int main() {
	LL total = 0;
	for (LL i = 1; ; i += 1) {
		total += i;
		if (n_divisors(total) > 500) {
			cout << total << endl;
			return 0;
		}
	}
	return 0;
}