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

LL solve() {
	for (int c = 1000; c > 0; c -= 1) {
		for (int b = c - 1; b > 0; b -= 1) {
			int a = 1000 - c - b;
			if (a > 0 && a < b && a * a + b * b == c * c) {
				return (LL)a * (LL)b * (LL)c;
			}
		}
	}
	return -1;
}

int main() {
	cout << solve() << endl;
	return 0;
}