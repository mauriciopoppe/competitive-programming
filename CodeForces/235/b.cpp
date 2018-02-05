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
vector<int> v(5000, 0);
int main() {
	int cur, past;
	int a, b, c;
	cin >> cur >> past;
	F(i, past) {
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			v[b] = 1; v[c] = 1;
		} else {
			cin >> b;
			v[b] = 1;
		}
	}

	int mn = 0, mx = 0;
	for (int i = 1; i < cur; i += 1) if (!v[i]) mx++;
	// printf("%d\n", mx);
	int i = 1, cnt = 0;
	while (i < cur) {
		if (!v[i]) cnt++;
		else mn += (int) ceil(cnt / 2.0), cnt = 0;
		++i;
	}
	if (cnt) mn += (int) ceil(cnt / 2.0);
	
	printf("%d %d\n", mn, mx);
	return 0;
}