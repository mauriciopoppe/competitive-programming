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

int d, y;
string m;

int leapYears(int y) {
	int m4 = y / 4;
	int m100 = y / 100;
	int m400 = y / 400;
	return m4 - m100 + m400;
}

int main() {
	int y1, y2;
	int cas;
	cin >> cas;
	F(z, cas) {
		// first
		cin >> m;		
		scanf("%d, %d", &d, &y);
		if (m == "January" || m == "February") y1 = y;
		else y1 = y + 1;

		// second
		cin >> m;
		scanf("%d, %d", &d, &y);
		if (d == 29 && m == "February") y2 = y;
		else if (m == "February" || m == "January") y2 = y - 1;
		else y2 = y;

		printf("Case %d: %d\n", z + 1, leapYears(y2) - leapYears(y1 - 1));
	}
	return 0;
}