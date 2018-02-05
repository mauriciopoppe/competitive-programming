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

int bill[3];

int solve(vi v) {
	F(i, v.size()) {
		if (v[i] == 1) bill[0]++;
		else if (v[i] == 2) {
			if (!bill[0]) return 0;
			bill[0]--; bill[1]++;
		} else {
			if (bill[0] && bill[1]) {
				bill[0]--; bill[1]--; bill[2]++;			
			} else if (bill[0] >= 3) {
				bill[0] -= 3; bill[2]++;
			} else {
				return 0;
			}
 		}
	}
	return true;
}

int main() {
	int n;
	while(cin >> n) {
		vi v(n);
		MS(bill, 0);
		F(i, n) {
			cin >> v[i];
			v[i] /= 25;
		}
		if (solve(v)) puts("YES");
		else puts("NO"); 
	}
	return 0;
}