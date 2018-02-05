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

// bool cmp(const pii &a, const pii &b) {
// 	if (a.first != b.first) return a.first < b.first;
// 	return a.second < b.second;
// }

int solve(vector<pair<int, int> > &v) {
	vector<pair<int, bool> > points;
	for (auto &it: v) {
		points.push_back(pair<int, bool>(it.first, true));
		points.push_back(pair<int, bool>(it.second, false));
	}
	sort(points.begin(), points.end());
	int max_points = 0;
	int cnt = 0;
	for (int i = 0; i < points.size(); i += 1) {
		if (points[i].second) {
			++cnt;
			max_points = max(max_points, cnt);
		} else {
			--cnt;
		}
	}
	return max_points;
}

int main() {
	vector<pii> p;
	p.push_back(pii(4, 5));
	p.push_back(pii(9, 17));
	p.push_back(pii(2, 7));
	p.push_back(pii(8, 9));
	p.push_back(pii(12, 15));
	p.push_back(pii(1, 5));
	p.push_back(pii(6, 10));
	p.push_back(pii(11, 13));
	p.push_back(pii(14, 15));
	cout << solve(p) << endl;
	return 0;
}