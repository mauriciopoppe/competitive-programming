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

int solve(vector<int> a) {
	int max_area = 0;
	a.push_back(0);
	// height, length
	stack<pair<int, int> > heights;
	for (int i = 0; i < a.size(); i += 1) {
		if (i == 0) {
			heights.push( pii(a[i], 1) );
		} else {
			if (a[i] == a[i - 1]) {
				pii &top = heights.top();
				top.second += 1;
			} else if (a[i] > a[i - 1]) {
				heights.push( pii(a[i], 1) );
			} else {	// a[i] < a[i - 1]
				int ac = 0;
				while (!heights.empty()) {
					pii &top = heights.top();
					if (top.first > a[i]) {
						ac += top.second;
						// printf("%d) %d %d\n", i, top.first, ac);
						max_area = max(max_area, ac * top.first);
						heights.pop();
					} else if (top.first == a[i]) {
						top.second += ac + 1;
						break;
					} else {
						heights.push( pii(a[i], ac + 1) );
						break;
					}
				}
			}
		}
	}
	return max_area;
}

int main() {
	vector<int> a = {1, 3, 4, 4, 2, 2, 1, 1};
	cout << solve(a) << endl;
	return 0;
}