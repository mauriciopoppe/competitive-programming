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
#include <iomanip>
#include <locale>
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

char decimal[1000], rep[1000];
int main() {
	// freopen("in", "r", stdin);
	// freopen("out", "w", stdout);
	int n;
	double balance;
	cin >> n;
	F(z, n) {
		double avg = 0;
		F(i, 12) cin >> balance, avg += balance;
		avg /= 12.0;
		sprintf(decimal, "%.2lf", avg);
		int size = strlen(decimal);

		// copy last 3
		int j = 0;
		for(int i = size - 1; i > size - 4; i--) rep[j++] = decimal[i];
		int i = size - 4, cnt = 0;
		while(i >= 0) {
			if (cnt == 3) {
				rep[j++] = ',';
				cnt = 0;
			}
			rep[j++] = decimal[i--];
			cnt += 1;
		}
		printf("%d ", z + 1);
		putchar('$');
		--j;
		while(j >= 0) {
			putchar(rep[j--]); 
		}
		NL;
	}	
	return 0;
}