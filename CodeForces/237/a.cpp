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

char m[1000][1000];

int sd(int n) {
	char s = m[0][0];
	for(int i = 0; i < n; i += 1) {
		if (m[i][i] != s) return false;
		if (m[i][n - i - 1] != s) return false;
	}
	return true;
}

int nd(int n) {
	char s = m[0][1];
	F(i, n)
		F(j, n) {
			if (i != j && j != n - i - 1) 
				if (m[i][j] != s) return false;
		}
	return true;
}

int main() {
	int n;
	cin >> n;
	F(i, n) scanf("%s", m[i]);
	if (n == 1) puts("YES");
	else if (sd(n) && nd(n)) puts("YES");
	else puts("NO");
	return 0;
}