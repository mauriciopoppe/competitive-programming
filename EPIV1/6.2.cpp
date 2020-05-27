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

int solve(vector<int> &v) {
	if (v.size() <= 1) {
		return 0;
	}
	int sol = numeric_limits<int>::min();
	int min_height = v[0];
	for (int i = 1; i < v.size(); i += 1) {
		sol = max(sol, v[i] - min_height);
		min_height = min(v[i], min_height);
	}
	return sol;
}


int main() {
	int a[] = {5,3,7,3,1,7,5,9,8,5};
	vector<int> v(a, a + sizeof a / sizeof a[0]);
	
	cout << solve(v) << endl;
	return 0;
}