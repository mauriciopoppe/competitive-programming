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

int solve(vector<int> &v, int ind, int k) {
	int t = 0, req;
	int base = v[ind];
	for (int i = 1; ind + i < v.size(); i += 1) {
		req = base + i * k;
		if (req < 1) return INF;
		if (v[ind + i] != req) ++t;
	}
	for (int i = 1; ind - i >= 0; i += 1) {
		req = base - i * k;
		if (req < 1) return INF;
		if (v[ind - i] != req) ++t;
	}
	return t;
}

int main() {
	int n, k, x, old = -1, first;
	while (cin >> n >> k) {
		vector<int> v(n);
		F(i, n) cin >> v[i];
		int mn = INF, index = -1;
		F(i, n) {
			int at = solve(v, i, k);
			if (at < mn) {
				mn = at;
				index = i;
			}
		}

		int cnt = 0;
		int mult;
		int base = v[index];
		stringstream ss;
		F(i, n) {
			mult = i - index;
			int req = base + mult * k;
			if(req != v[i]) {
				ss << (req > v[i] ? "+" : "-");
				ss << " ";
				ss << (i + 1);
				ss << " ";
				ss << abs(req - v[i]);
				ss << "\n";
				cnt += 1;
			}
		}
		printf("%d\n%s", cnt, ss.str().c_str());
	}
	return 0;
}