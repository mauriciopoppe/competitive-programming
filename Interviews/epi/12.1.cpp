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

int bsearch(vector<int> &v, int value) {
	int low = -1, high = v.size() - 1;
	while (high - low > 1) {
		int mid = low + (high - low) / 2;
		if (v[mid] >= value) {
			high = mid;
		} else {
			low = mid;
		}
	}
	if (v[high] == value) {
		return high;
	}
	return -1;
}

int main() {
	int t[] = {-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};
	vector<int> v(t, t + 10);
	cout << bsearch(v, 108) << endl;
	cout << bsearch(v, 285) << endl;
	cout << bsearch(v, 401) << endl;
	cout << bsearch(v, -1) << endl;
	return 0;
}