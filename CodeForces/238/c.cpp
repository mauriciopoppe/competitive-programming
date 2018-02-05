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

int main() {
	int n, q, k;
	while (cin >> n) {
		vector<int> v(n);
		int res = 0;
		F(i, n) F(j, n) {
			scanf("%d", &k);
			if (i == j) {
				v[i] = k;
				res += k;
			}
		}
		cin >> q;
		int type;
		F(i, q) {
			scanf("%d", &type);
			if (type == 1 || type == 2) {
				scanf("%d", &k);
				k--;
				v[k] = 1 - v[k];
				if (!v[k]) res--;
				else res++;
			} else {
				printf("%d", res % 2);
			}
		}
		NL;
	}	
	return 0;
}