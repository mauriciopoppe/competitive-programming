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

bool solve(vector<int> a, int t) {
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); i += 1) {
		int target = t - a[i];
		int left = 0, right = a.size() - 1;
		while (left <= right) {
			if (a[left] + a[right] == target) {
				printf("%d %d %d\n", a[i], a[left], a[right]);
				return true;
			}
			if (a[left] + a[right] > target) {
				right -= 1;
			} else {
				left += 1;
			}
		}
	}
	return false;
}

int main() {
	vector<int> a = {12, 3, 4, 1, 6, 9};
	cout << solve(a, 24) << endl;
	return 0;
}