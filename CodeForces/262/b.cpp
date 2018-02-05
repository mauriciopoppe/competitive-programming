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

LL m(LL n, LL t) {
	LL total = 1LL;
	F (i, t) total *= n;
	return total;
}

int cnt(LL c) {
	int s = 0;
	while (c) {
		s += c % 10LL;
		c /= 10LL;
	}
	return s;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	LL a, b, c;
	LL x;
	while (cin >> a >> b >> c) {
		vector<LL> v;

		for (int i = 1; i <= 9 * 9; i += 1) {
			LL x = b * m(i, a) + c;
			if (x > 0 && x < 1e9 && cnt(x) == i) {
				v.push_back(x);
			}
		}

		cout << v.size() << endl;
		F(i, v.size()) {
			if (i) cout << " ";
			cout << v[i];
		}
		cout << endl;
	}
	return 0;
}