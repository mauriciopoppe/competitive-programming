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

int solve(vi v, int n) {
	for (int i = 1; i < n - 1; i += 1) {
		for (int j = 0; j < i; j += 1) {
			
			int mna = min(v[j], v[j + 1]);
			int mxa = max(v[j], v[j + 1]);

			int mnb = min(v[i], v[i + 1]);
			int mxb = max(v[i], v[i + 1]);
			
			if (mna < mnb && mnb < mxa) {
				if (mxb > mxa) {
					// printf("%d %d - %d %d\n", mna, mxa, mnb, mxb);
					return true;
				}
			} else if (mna < mxb && mxb < mxa) {
				if (mna > mnb) {
					// printf("%d %d - %d %d\n", mna, mxa, mnb, mxb);
					return true;				
				}
			}
		}
	}
	return false;
}

int main() {
	int n;
	while (cin >> n) {
		vi v(n);
		F(i, n) cin >> v[i];
		printf("%s\n", solve(v, n) ? "yes" : "no");	
	}
	return 0;
}