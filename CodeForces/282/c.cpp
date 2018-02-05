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

vector<int> solve(string s) {
	vector<int> l(s.size() + 1, 0);
	vector<int> r(s.size() + 1, 0);

	int hashes = 0;

	for (int i = 0; i < s.size(); i += 1) {
		l[i + 1] = l[i];
		r[i + 1] = r[i];
		if (s[i] == '(') {
			l[i + 1] += 1;
		} else {
			r[i + 1] += 1;
		}

		if (r[i + 1] > l[i + 1]) {
			return vector<int> {-1};
		}

		if (s[i] == '#') {
			hashes += 1;
		}
	}

	vector<int> answer(hashes, 1);

	for (int i = s.size() - 1; i >= 0; i -= 1) {
		int lefts = l[s.size()] - l[i + 1];
		int rights = r[s.size()] - r[i + 1];
		if (lefts > rights) {
			return vector<int> {-1};
		}

		if (s[i] == '#') {
			int open = l[i] - l[0];
			int close = r[i] - r[0];

			int to_add = open - close - (rights - lefts);			
			if (to_add <= 0) {
				return vector<int> {-1};
			}
			
			answer[hashes - 1] = to_add;
			return answer;
		}
	}
}

int main() {
	string s;
	while (cin >> s) {
		vector<int> ans = solve(s);
		for (int i = 0; i < ans.size(); i += 1) {
			printf("%d\n", ans[i]);
		}
 	}
	return 0;
}