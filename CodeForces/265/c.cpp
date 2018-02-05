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

string str;
int n, mx;
bool isp(int from, int to) {
	// printf("%d %d %s\n", from, to, str.c_str());
	while (from < to) {
		if (str[from++] != str[to--]) return false;
	}
	return true;
}

bool solve(int from) {
	// puts("solution");
	for (int i = from + 1; i < n; i += 1) {
		for (int j = 0; j < mx; j += 1) {
			str[i] = 'a' + j;
			int k;
			for(k = 1; k <= i; k += 1) {
				if (isp(i - k, i)) break;
			}
			if (k == i + 1) {
				break;
			}
		}
	}
}

int main() {
	while (cin >> n >> mx) {
		cin >> str;
		int is_solved = false;
		for (int i = n - 1; !is_solved && i >= 0; i -= 1) {
			int original = str[i];
			while (++str[i] < mx + 'a') {
				int k;
				for(k = 1; k <= i; k += 1) {
					if (isp(i - k, i)) {
						break;
					}
				}
				if (k == i + 1) {
					is_solved = true;
					solve(i);
					break;
				}
			}
		}
		if (is_solved) {
			cout << str << endl;
		} else {
			puts("NO");
		}
	}
	return 0;
}

// abdc