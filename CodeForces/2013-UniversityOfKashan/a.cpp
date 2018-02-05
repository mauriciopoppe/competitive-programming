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

int solve(vi v) {
	if (v[0] == v[1] && v[1] == v[2]) {
		if (v[0]) return 6;
		return 0;
	}
	int mn = v[0];
	v[1] -= v[0];
	v[2] -= v[0];
	v[0] = 0;

	if (v[0] == 0 && v[1] == 1 && v[2] == 1) return 2;
	if (v[0] == 0 && v[1] == 0 && v[2] == 1) {
		if (mn) return 2;
		return 1;
	}
	return 0;
}

int main() {
	int cas;
	cin >> cas;
	F(z, cas) {
		vi v(3);
		F(i, 3) cin >> v[i];
		sort(ALL(v));
		printf("%d\n", solve(v));
	}
	return 0;
}