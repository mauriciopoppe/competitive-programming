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

int solve(vector<int> v) {
	vector<int> ltor;
	int min_height = v[0];
	int best;
	best = numeric_limits<int>::min();
	for (int i = 1; i < v.size(); i += 1) {
		best = max(best, v[i] - min_height);
		ltor.push_back(best);
		min_height = min(min_height, v[i]);
	}

	vector<int> rtol;
	int max_height = v[v.size() - 1];
	best = numeric_limits<int>::min();
	for (int i = v.size() - 2; i >= 0; i -= 1) {
		best = max(best, max_height - v[i]);
		rtol.push_back(best);
		max_height = max(max_height, v[i]);
	}

	best = numeric_limits<int>::min();
	assert(ltor.size() == rtol.size());
	for (int i = 0, j = ltor.size() - 3; j >= 0; i += 1, j -= 1) {
		// cout << ltor[i] << " " << rtol[j] << endl;
		best = max(ltor[i] + rtol[j], best);
	}
	return best;
}


int main() {
	int a[] = {5,3,7,3,1,7,5,9,8,5};
	vector<int> v(a, a + sizeof a / sizeof a[0]);	
	cout << solve(v) << endl;
	return 0;
}