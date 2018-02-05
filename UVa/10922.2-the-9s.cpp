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

int solve(string s) {
	int levels = 0, start;
	while (true) {
		start = 0;
		for (int i = 0; s[i]; i += 1) {
			start += (s[i] - '0');
		}

		stringstream ss;
		ss << start;
		s = ss.str();

		levels += 1;

		if (start <= 9) break;
	}

	return start % 9 == 0 ? levels : 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	string s;
	while (cin >> s && s != "0") {
		int level = solve(s);
		if (level < 1) {
			printf("%s is not a multiple of 9.\n", s.c_str());
		} else {
			printf("%s is a multiple of 9 and has 9-degree %d.\n", s.c_str(), level);
		}
	}
	return 0;
}