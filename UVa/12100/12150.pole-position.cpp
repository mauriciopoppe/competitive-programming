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

vi v(100005);

int solve(int n) {
	F(i, n) v[i] = -1;
	int sm = 0;
	int c, p;
	int isValid = 1;
	F(i, n) {
		cin >> c >> p;
		if(!isValid) continue;
		sm += 0;
		int np = i + p;
		if (np < 0 || np >= n || v[np] != -1) isValid = 0;
		else v[np] = c;
	}
	return isValid;
}

int main() {
	
	int n;
	while (cin >> n && n) {
		if (solve(n)) {
			for (int i = 0; i < n; i += 1) {
				if (i) printf(" ");
				printf("%d", v[i]);
			}
			NL;
		} else {
			puts("-1");
		}
	}

	return 0;
}