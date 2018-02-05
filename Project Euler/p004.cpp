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

int pal(int n) {
	int cp = n;
	int newN = 0;
	while (cp) {
		newN = newN * 10 + cp % 10;
		cp /= 10;
	}
	return newN == n;
}

int main() {
	int mx = 0;
	for (int i = 999; i >= 100; i -= 1) {
		for (int j = i; j >= 100; j -= 1) {
			if (pal(i * j)) {
				mx = max(i * j, mx);
			}
		}
	}
	cout << mx << endl;

	return 0;
}