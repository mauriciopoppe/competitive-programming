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
	int n, b;
	while (cin >> n >> b && n && b) {
		vector<int> v(b);
		vector<int> c(n + 1);
		F(i, b) cin >> v[i];
		F(i, b) {
			F(j, b) {
				c[abs(v[i] - v[j])] = 1;
			}
		}
		int good = true;
		F(i, n + 1) good &= c[i];
		printf("%s\n", good ? "Y" : "N");
	}	
	return 0;
}