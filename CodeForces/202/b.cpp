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

int v;
vi d(10);

int main() {
	while (cin >> v) {
		int indexMin = 0;
		F(i, 9) {
			cin >> d[i];
			if (d[indexMin] >= d[i]) {
				indexMin = i;
			}
		}

		int digits = v / d[indexMin],
			j;

		if (!digits) puts("-1");
		else {
			v %= d[indexMin];
			F(i, digits) {
				for (j = 8; j > indexMin; j -= 1) {
					if (d[j] - d[indexMin] <= v) {
						v -= d[j] - d[indexMin];
						break;
					}
				}
				putchar(j + '1');
			}
			NL;
		}
	}
	return 0;
}