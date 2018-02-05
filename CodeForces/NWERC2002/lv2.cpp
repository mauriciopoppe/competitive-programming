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

// AAABBBAAA
#define M 1000101
int f[M], g[M];
int main() {
	int n;
	string s;
	while (cin >> n) {
		cin >> s;
		f[0] = g[0] = 0;
		for (int i = 1; i <= n; i += 1) {
			if (s[i - 1] == 'A') {
				f[i] = f[i - 1];				
				g[i] = min(f[i - 1] + 1, g[i - 1] + 1);
			} else {
				g[i] = g[i - 1];
				f[i] = min(f[i - 1] + 1, g[i - 1] + 1);
			}
		}
		printf("%d\n", f[n]);
	}
	return 0;
}