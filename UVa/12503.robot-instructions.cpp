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
	int cas;
	string s;
	cin >> cas;
	while(cas--) {
		int n, k;
		cin >> n;
		vector<int> v(n);
		F(i, n) {
			cin >> s;
			if (s == "LEFT") v[i] = -1;
			else if(s == "RIGHT") v[i] = 1;
			else {
				cin >> s >> k;
				v[i] = v[k - 1];
			}
		}

		int p = 0;
		F(i, n) p += v[i];
		printf("%d\n", p);
	}	
	return 0;
}