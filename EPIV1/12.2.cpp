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

int find_min(vector<int> &v) {
	int high = v.size() - 1, low = -1;
	while (high - low > 1) {
		int mid = low + (high - low) / 2;
		if (v[mid] < v[v.size() - 1]) {
			high = mid;
		} else {
			low = mid;
		}
	}
	return v[high];
}

int main() {
	int t[] = {285, 285, 285, 401, -14, -10, 2, 108, 108, 243};
	vector<int> v(t, t + 10);
	cout << find_min(v) << endl;
	return 0;
}