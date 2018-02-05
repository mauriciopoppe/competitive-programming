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

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int px[] = {0, 1, 1, 0};
int py[] = {0, 0, 1, 1};

int main() {
	int x = 0, y = 0;
	double len, d;
	int n;
	while (cin >> len >> d >> n) {
		double cur = 0;
		while (n--) {
			cur += d;
			int i = (int)(cur / len);
			int lower = i % 4;
			double k = cur - i * len;
			printf("%.10lf %.10lf\n", (int)((px[lower] * len + dx[lower] * k) * 10000) / 10000.0 , (int)((py[lower] * len + dy[lower] * k) * 10000) / 10000.0) ;
		}
	}
	return 0;
}