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

	vector<int> p;
	p.push_back(2);
	for (int i = 3; p.size() < 10002; i += 2) {
		int divisible = false;
		for (int j = 0; j < p.size(); j += 1) {
			if (i % p[j] == 0) {
				divisible = true;
				break;
			}
		}
		if (!divisible) {
			p.push_back(i);
		}
	}
	cout << p[10000] << endl;

	return 0;
}