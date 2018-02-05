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

int solve (int n) {
	while (n) {
		if ((n * 5) % 9 == 0) return n;
		--n;
	}
	return 0;
}

int main() {
	// freopen("in", "r", stdin);
	// freopen("out", "w", stdout);
	
	int n, k;
	while (cin >> n) {
		int five = 0, zero = 0;
		F(i, n) {
			cin >> k;
			if (k == 5) five++;
			else zero++;
		}

		int s = solve(five);
		if (s) {
			F(i, s) printf("5");
			F(i, zero) printf("0");
			printf("\n");
		} else {
			puts("0");
		}
	}
	return 0;
}