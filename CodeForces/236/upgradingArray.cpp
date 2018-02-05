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
#define L 100000

map<int, bool> bp;

vector<int> p;
int s;
bool v[L];
void gen() {
	for (int i = 3; i * i < L; i += 2) {
		if (!v[i])
			for (int j = i * i; j < L; j += 2 * i) v[j] = 1;
	}
	p.push_back(2);
	for (int i = 3; i < L; i += 2) if (!v[i]) p.push_back(i);
	s = p.size();
}

int f(int x) {
	int res = 0;
	for (int i = 0; i < s && p[i] * p[i] <= x; i += 1) {
		while (x % p[i] == 0) {
			x /= p[i];
			if (bp[p[i]]) res--;
			else res++;
		}
	}
	if (x > 1) {
		if (bp[x]) res--;
		else res++;
	}
	return res;
}

int main() {
	gen();
	int n, m, k;
	while (cin >> n >> m) {
		bp.clear();
		vector<int> a(n);
		vector<int> GCD(n);
		F(i, n) {
			cin >> a[i];
			if (!i) GCD[i] = a[i];
			else GCD[i] = __gcd(a[i], GCD[i - 1]);
		}
		F(i, m) {
			int badPrime;
			cin >> badPrime;
			bp[badPrime] = 1;
		}
		
		int dvGcd = 1;
		vector<int> divisors(n, 1);
		for (int i = n - 1; i >= 0; i -= 1) {
			GCD[i] /= dvGcd;
			int x = f(GCD[i]);
			if (x < 0) dvGcd *= GCD[i];
			divisors[i] = dvGcd;
		}		
		int t = 0;
		F(i, n) {
			// printf("< %d\n", v[i]);
			a[i] /= divisors[i];
			t += f(a[i]);
		}
		printf("%d\n", t);
	}

	return 0;
}