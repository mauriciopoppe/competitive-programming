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

int main() {
	LL gcd = 1;
	for (LL i = 1; i <= 20; i += 1) {
		gcd = gcd * i / __gcd(gcd, i);
		// if (gcd % 2 != 0) {
		// 	gcd *= 2;
		// }
	}
	cout << gcd << endl;
	return 0;
}