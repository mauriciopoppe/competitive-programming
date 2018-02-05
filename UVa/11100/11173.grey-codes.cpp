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
	int n, k;
	int number = 0;
	int cas;
	cin >> cas;
	while (cas--) {
		cin >> n >> k;
		int total = 0;
		for (int i = 0; i < n; i += 1) {
			int con = 1 << (i + 1);
			int pre = con >> 1;
			int temp = k;
			if (temp < pre) continue;
			temp -= pre;
			temp /= con;
			if (temp % 2 == 0) {
				total |= (1 << i);
			}
		}
		printf("%d\n", total);
	}	
	return 0;
}