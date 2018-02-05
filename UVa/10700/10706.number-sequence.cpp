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

vector<LL> sm(1000005);
vector<LL> digits(1000005);
int size;

LL binarySearch(LL k) {
	int lo = 0, hi = size;
	while (hi - lo > 1) {
		int m = lo + (hi - lo) / 2;
		if (sm[m] > k) hi = m;
		else lo = m;
	}
	// printf("%d\n", lo);
	return sm[lo];
}

int main() {
	size = 0;
	sm[size] = 0;
	digits[size] = 0;
	++size;

	stringstream ss;
	string ans = "";
	for (int i = 1; sm[i - 1] <= ((LL)1 << 31) - 1; i += 1) {
		digits[size] = digits[size - 1] + (int) floor(log10(i)) + 1;		
		sm[size] = sm[size - 1] + digits[size];
		++size;
	}

	// F(i, 10) printf("%lld\n", sm[i]);
	// printf("%lld\n", digits[size - 1]);

	int cnt = 0;
	for (int i = 1; i <= size; i += 1) {
		ss << i;	
	}
	ans = ss.str();
	// cout << ans.substr(0, 20) << endl;
	
	int cas;
	LL k;
	cin >> cas;
	while (cas--) {
		cin >> k;
		k--;
		LL lower = binarySearch(k) - 1;
		k -= lower;
		// printf("lower = %lld k = %lld\n", lower, k);
		printf("%c\n", ans[(int)(k - 1)] );
	}

	return 0;
}