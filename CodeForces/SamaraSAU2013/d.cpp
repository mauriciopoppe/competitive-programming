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
int n;
int main() {
	string a, b, c;
	while (cin >> n) {
		cin >> a >> b >> c;
		
		string res = "";
		F(i, n) {
			if (a[i] == b[i] && b[i] == c[i]) res += a[i];
			else if (a[i] == b[i]) res += a[i];
			else if (b[i] == c[i]) res += b[i];
			else if (a[i] == c[i]) res += a[i];
			else res += a[i];
		}

		cout << res << endl;
	}
	return 0;
}