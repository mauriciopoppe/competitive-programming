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

// 5 9 10
// 2 4 12
// 3 7  8
// 1 6 11
void remove(map<int, int> &m, int r) {
	m[r]--;
	if (m[r] == 0) {
		m.erase(r);
	}
}

int main() {
	int n;
	while (cin >> n) {
		vector<vi> v(n);
		map<int, int> mn, mx;
		F(i, n) {
			v[i] = vector<int>(3);
			F(j, 3) cin >> v[i][j];
			sort(ALL(v[i]));
			mn[v[i][0]]++;
			mx[v[i][1]]++;
		}

		if (n == 1) {
			printf("1\n1\n");
			continue;
		}
		vi sol;
		F(i, n) {
			int a = v[i][0],
				b = v[i][1],
				c = v[i][2];
			remove(mn, a);
			remove(mx, b);

			// printf("%d - %d %d\n", i, (mn.rbegin())->first, (mx.rbegin())->first);;
			// find max
			if ( mn.size() && mx.size() && (mn.rbegin())->first < b &&
				 (mx.rbegin())->first < c )
				sol.push_back(i + 1);

			mn[a]++;
			mx[b]++;
		}

		printf("%d\n", (int)sol.size());
		TR(sol, it) {
			printf("%d ", *it);
		}
		NL;
	}
	return 0;
}