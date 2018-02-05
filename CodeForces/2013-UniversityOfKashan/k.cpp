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

#define M 1000001
int tp, n;
int primes[M];
int b[M + 1234];
int a[M];
int sm[M];

void gen() {
	MS(b, 0);
	for(int i = 3; i * i <= M; i += 2) {
		if (!b[i]) {
			for (int j = i * i; j <= M; j += 2 * i)
				b[j] = 1;
		}
	}
	tp = 0;
	primes[tp++] = 2;
	for (int i = 3; i <= M; i += 2) if (!b[i]) primes[tp++] = i;
}

vi solve(vi all, int n) {
	vi s(2);
	s[0] = 1; s[1] = 1;
	reverse(ALL(all));
	for (int i = 0, size = all.size(); i < size; i += 1) {
		int current = all[i];
		// test 0
		// if (sm[n] % current == 0) {
		// 	// printf("0: %d %d\n", sm[n - 1], current);
		// 	s[0] = current; s[1] = 0;
		// 	return s;
		// }

		// test 1
		for (int j = 1; j < n; j += 1) {
			if (sm[j] % current == 0) {
			// printf("1: %d %d\n", sm[j], current);
				s[0] = current; s[1] = 1;
				return s;
			}

			// from the right
			if ( (sm[n] - sm[n - j]) % current == 0 ) {
			// printf("1: %d %d\n", sm[n - 1] - sm[n - j - 2], current);
				s[0] = current; s[1] = 1;
				return s;
			}
		}

		// test 2
		for (int j = 1; j < n; j += 1) {
			for (int k = j + 1; k < n; k += 1) {
				// printf("%d %d\n", j, k);
				int partial = sm[k] - sm[j];
				if ( partial && (partial % current == 0) ) {
					// printf("2: %d %d\n", partial, current);
			
					s[0] = current; s[1] = 2;
					return s;
				}
			}
		}
	}

	return s;
}

int main() {
	// freopen("in", "r", stdin);
	// freopen("out", "w", stdout);
	
	gen();
	int cas; cin >> cas;
	while (cas--) {
		int product;
		cin >> n >> product;
		F(i, n) cin >> a[i];

		// solve product
		vi p;
		for (int i = 0; i < tp && product != 1; i += 1) {
			if (product % primes[i] == 0) {
				p.push_back(primes[i]);
				product /= primes[i];
			}
		}

		// all permutations
		vi all;
		for (int i = 1, total = p.size(); i < (1 << total); i += 1) {
			product = 1;
			for (int j = 0; j < total; j += 1) {
				if (i & (1 << j)) product *= p[j];
			}
			all.push_back(product);
		}

		sort(ALL(all));
		// TR(all, it) printf("%d ", *it);NL;

		// calc sum
		sm[0] = 0;
		for (int i = 0; i < n; i += 1) {
			sm[i + 1] = sm[i] + a[i];
		}

		// bf!
		vi s = solve(all, n);
		printf("%d %d\n", s[0], s[1]);

	}
	return 0;
}