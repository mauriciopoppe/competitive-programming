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

int factorize(int n, int limit) {
	int total = 0;
	for (int i = 1; i * i <= n; i += 1) {
		if (n % i == 0) {
			if (i > limit) {
				total += 1;
			}
			if (n / i > limit) {
				total += 1;
			}
			if (i == n / i && i > limit && n / i > limit) {
				total -= 1;
			}
		}
	}
	return total;
}

int main() {
	int a, b;
	while (cin >> a >> b) {
		int diff = a - b;
		if (a < b) {
			printf("0\n"); 			
		} else if (a == b) {
			printf("infinity\n");
		} else {
			printf("%d\n", factorize(diff, b));
		}
	}
	return 0;
}