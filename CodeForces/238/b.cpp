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
	int n;
	string s;
	while (cin >> n >> s) {
		vector<int> v(n);
		F(i, n) {
			if (s[i] == 'L') v[i] = -1;
			else if (s[i] == 'R') v[i] = 1;
			else v[i] = 0;
		}

		// F(j, n) printf("%2d ", v[j]); NL;
		F(i, n) {
			vector<int> vc = v;
			F(j, n) {
				if(v[j] == 1 && j + 1 < n) {
					if (v[j + 1] != -1)
						vc[j + 1] = min(vc[j + 1] + 1, 1);
				}
				else if (v[j] == -1 && j - 1 >= 0) {
					if (v[j - 1] != 1)
						vc[j - 1] = max(vc[j - 1] - 1, -1);
				}
				
			}
			// F(j, n) printf("%2d ", vc[j]); NL;
			v = vc;
		}
		int cnt = 0;
		F(i, n) if(!v[i]) ++cnt;
		printf("%d\n", cnt);
	}	
	return 0;
}