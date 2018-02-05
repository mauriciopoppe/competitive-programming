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

#define M 1000005
LL v[M];
int tv;

int isValid(LL v) {
	while (v) {
		int m = v % 10;
		if (!(m == 0 || m == 1 || m == 4 || m == 9)) {
			return false;
		}
		v /= 10;
	}
	return true;
}

void gen() {
	tv = 0;
	LL i = 1;
	LL mx = 10000000000LL;
	while (1) {
		LL cd = i * i;
		if (isValid(cd)){
			v[tv++] = cd;
		}
		if (cd > mx) break;
		++i;
	}	
}

int main() {
	gen();
	int cas;
	LL a, b;
	cin >> cas;
	while (cas--) {
		scanf("%lld%lld", &a, &b);
		int low = lower_bound(v, v + tv, a) - v;
		int up = upper_bound(v, v + tv, b) - v;
		printf("%d\n", up - low);
	}
	return 0;
}