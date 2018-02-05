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

LL f(LL x) {
	LL total = 0;
	LL ps = 0;
	LL i = 0;

	LL c = 0;
	while (x) {
		if (x & 1) {
			total += c;
			total += (1LL << (i - 1)) * i;
			c |= 1LL << i;
		}
		++i;
		x /= 2;
	}
	return total;
}

int main() {
	LL a, b;
	while (cin >> a >> b) {
		// printf("%lld\n", f(a + 1));
		printf("%lld\n", f(b + 1) - f(a));
	}
	return 0;
}