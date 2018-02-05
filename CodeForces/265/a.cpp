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

#define M 1001

int main() {
	int n;
	string str;
	while (cin >> n) {
		cin >> str;
		int total = 0;
		F(i, str.size()) {
			if (str[i] == '1') ++total;
			else break;
		}
		printf("%d\n", min(total + 1, (int)str.size()));
	}
	return 0;
}