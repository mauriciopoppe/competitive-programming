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

string solve(int n, int m) {
	stringstream ss;
	int endedInZero = false;
	while (n && m) {
		if (m == n - 1) {
			stringstream pre;
			pre << "0";
			F(i, m) pre << "10";
			return pre.str() + ss.str();
		} else if (n == m) {
			F(i, m) ss << "10"; n = m = 0; break;
		} else {
			endedInZero = true;
			ss << "110";
			n--;
			m -= 2;
		}
	}
	while (m--) ss << "1";
	while (n--) ss << "0";
	return ss.str();
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		if ((n - 1) <= m && m <= 2 * (n + 1)) {
			cout << solve(n, m) << endl;
		} else {
			puts("-1");
		}
	}	
	return 0;
}