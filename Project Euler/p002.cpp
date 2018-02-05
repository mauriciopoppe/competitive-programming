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
	int limit = 4000000;
	int a = 1, b = 2;
	int sum = 2;
	for (int i = 1; ; i += 1) {
		int c = a + b;
		if (c > limit) {
			break;
		}
		if (c % 2 == 0) {
			sum += c;
		}
		a = b;
		b = c;
	}
	cout << sum << endl;
	return 0;
}