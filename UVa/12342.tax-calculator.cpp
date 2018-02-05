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

int a[] = {180000, 300000, 400000, 300000};
double tax[] = {0, 0.1, 0.15, 0.2};

int main() {
	int n, m;
	cin >> n;
	F(z, n) {
		cin >> m;

		int totalTax = 0;
		F(i, 4) {
			if (m <= 0) continue;

			int am = min(m, a[i]);
			int paid;
			if (am > 0) paid = (int) ceil(tax[i] * (double)am);
			totalTax += paid;
			m -= am;
		}
		if (m > 0) totalTax += (int) ceil(0.25 * (double)m);
		if (totalTax) totalTax = max(totalTax, 2000);
		printf("Case %d: %d\n", z + 1, totalTax);
	}	
	return 0;
}