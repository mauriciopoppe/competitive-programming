#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <sstream>
#include <utility>
#include <numeric>
#include <functional>
using namespace std;
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define X first
#define Y second
#define MS(a, v) memset(a, v, sizeof a)
#define NL printf("\n")
#define SP system("pause")
#define INF 1e9
#define PI acos(-1)
#define EPS 1e-9
#define TR(ar, it) for ( decltype(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

int flip(int n, int i) {
	return n ^ (1 << i);
}

int main() {
	int n;
	while (cin >> n) {
		int mx = 1 << n;
		vi v(mx);
		vi pc(mx);
		F(i, mx) {
			cin >> v[i];
		}

		int best = 0;
		F(i, mx) {
			int total = 0;
			F(j, n) {
				int other = flip(i, j);
				total += v[other];
			}
			pc[i] = total;
		}
		F(i, mx) {
			F(j, n) {
				int other = flip(i, j);
				best = max(best, pc[i] + pc[other]);
			}
		}
		printf("%d\n", best);
	}
	return 0;
}