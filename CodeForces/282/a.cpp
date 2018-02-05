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
	map<int, int> m;
	m[0] = 2; // 0 8
	m[1] = 7;
	m[2] = 2;
	m[3] = 3;
	m[4] = 3;
	m[5] = 4;
	m[6] = 2;
	m[7] = 5;
	m[8] = 1;
	m[9] = 2;

	int n;
	cin >> n;
	printf("%d\n", m[n % 10] * m[n / 10]);

	return 0;
}