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
	int n;
	while (cin >> n) {
		vector<int> v;
		int l;
		F(i, n) {
			cin >> l;
			if (l == 1) {
				v.push_back(i);
			}
		}
		int total = 0;
		if (v.size()) {
			++total;
			for (int i = 1; i < v.size(); i += 1) {
				if (v[i] - v[i - 1] > 2) total += 2;
				else total += v[i] - v[i - 1];
			}
		}
		printf("%d\n", total);
	}
	return 0;
}