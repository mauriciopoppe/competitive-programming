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

#define M 1000123
int isDead[M];
int s[M];
int r[M], l[M];

int find_alive(int now, int *v) {
	if (!isDead[now]) return now;
	return find_alive(v[now], v);
}

int main() {
	int n, c;
	int from, to;
	while (cin >> n >> c) {
		if (n + c == 0) break;

		F(i, n + 10) {
			l[i] = i - 1;
			r[i] = i + 1;
			isDead[i] = 0;
		}

		F(i, c) {
			scanf("%d%d", &from, &to);			
			int ri = find_alive(to + 1, r);
			int le = find_alive(from - 1, l);
			for(int j = from; j <= to; j += 1) {
				isDead[j] = 1;
				r[j] = ri;
				l[j] = le;
			}
			
			if (le == 0) printf("* ");
			else printf("%d ", le);

			if (ri == n + 1) printf("*");
			else printf("%d", ri);
			NL;
		}
		puts("-");
	}
	return 0;
}