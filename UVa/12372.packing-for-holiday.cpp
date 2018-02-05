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

int main() {
	int cas;
	cin >> cas;
	int a, b, c;
	for (int i = 0; i < cas; i += 1) {
		cin >> a >> b >> c;
		printf("Case %d: ", i + 1);
		if (a > 20 || b > 20 || c > 20) {
			printf("bad");
		} else {
			printf("good");
		}
		NL;
	}
	return 0;
}