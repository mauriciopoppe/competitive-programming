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
#define INF 1000000000000000000LL
#define PI acos(-1)
#define EPS 1e-9
#define TR(ar, it) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

int today(string a, string b) {
	sort(ALL(a)); sort(ALL(b));
	return a == b;
}

int yesterday(string a, string b) {
	set<char> wa(ALL(a)), wb(ALL(b));
	return wa == wb;
}

int main() {
	// freopen("in", "r", stdin);
	// freopen("out", "w", stdout);
	
	int n;
	string a, b;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		if (yesterday(a, b) == today(a, b)) puts("YES");
		else puts("NO");
	}
	return 0;
}