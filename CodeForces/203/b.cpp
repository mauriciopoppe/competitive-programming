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

#define M 100005
int n;
int parent[M];
int is_hotel[M];
int valid[M];

vi solve(int i) {
	vi v;
	while (1) {
		v.push_back(i);
		if (parent[i] < 0) break;
		if (valid[parent[i]] < 1) break;
		i = parent[i];
	}
	return v;
}

int main() {
	while (cin >> n) {
		F(i, n) {
			cin >> is_hotel[i];
			valid[i] = 2;
		}
		F(i, n) {
			cin >> parent[i];
			parent[i]--;
			if (parent[i] >= 0)
				valid[parent[i]]--;
		}

		// F(i, n) printf("%d %d valid=%d\n", is_hotel[i], parent[i], valid[i]);

		int best = 0;
		vi vbest;
		F(i, n) {
			if (is_hotel[i]) {
				vi v = solve(i);
				if (v.size() > best) {
					best = v.size();
					vbest = v;
				}
			}
		}
		printf("%d\n", best);
		for (int i = best - 1; i >= 0; i -= 1) {
			printf("%d ", vbest[i] + 1);
		}
		NL;
	}

	return 0;
}