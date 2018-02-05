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

void solve(vector<int> &el, int step, int mask) {
	if (step == el.size()) {
		cout << "{";
		for (int i = 0; i < step; i += 1) {
			if (mask & (1 << i)) {
				cout << el[i] << ",";
			}
		}
		cout << "}" << endl;
	} else {
		solve(el, step + 1, mask);
		solve(el, step + 1, mask | (1 << step));		
	}
}

int main() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	solve(v, 0, 0);
	return 0;
}