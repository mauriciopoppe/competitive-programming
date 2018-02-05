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
#define TR(ar, it) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

int p[100005];

int solve(int n) {
	int i,
		pos,
		mx = 0;
	for (i = 0; i < n; i += 1) {
		pos = p[i];
		if (pos != i) {

		 	// swap
		 	mx = max(mx, 1);
			if (p[p[i]] == i) {
				mx = max(mx, 2);
			}

		}
	}
	return mx;
}

int main() {
	int n, k;
	while (cin >> n) {
		int total = 0;
		MS(p, 0);
		F(i, n) {
			cin >> k;
			p[k] = i;
			if (k == i) total += 1;
		}
		total += solve(n);
		printf("%d\n", total);
	}
	return 0;
}