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
vi minify(string &s) {
	char start = s[0];

	vi sol;
	int cnt = 1;
	for (int i = 1; i < n; i += 1) {
		if (s[i] != start) {
			sol.push_back(cnt);
			start = s[i];
			cnt = 0;
		}
		cnt++;
	}
	sol.push_back(cnt);
	return sol;
}

int BA(string &s) {
	// BA
	vi b;
	for (int i = 1; i < n - 1; i += 1) {
		if (s[i - 1] == 'A' && s[i] == 'B' && s[i + 1] == 'A') {
			b.push_back(i);
		}
	}
	if (n >= 2 && s[n - 2] == 'A' && s[n - 1] == 'B')
		b.push_back(n - 1);
	TR(b, it) s[*it] = 'A';
	return b.size();
}

int AB(string &s) {
	vi b;
	for (int i = 1; i < n - 1; i += 1) {
		if (s[i - 1] == 'B' && s[i] == 'A' && s[i + 1] == 'B') {
			b.push_back(i);
		}
	}
	TR(b, it) s[*it] = 'B';
	return b.size();
}

int main() {
	string s;
	while (cin >> s) {
		// cin >> s;

		// AAAAABBBBBBBBBAAAA
		n = s.size();
		
		int total = 0;
		total += BA(s);
		total += AB(s);
		vi v = minify(s);
		int size = v.size();
		int sb = s[0] == 'B';
		
		// AB
		// ABA
		if (sb) {
			total += 1;
			--size;
		}
		if (size > 1) {
			if (size % 2 == 0) {
				// ABAB
				total += size;
			} else {
				// ababa
				total += size - 1;
			}
		}

		printf("%d\n", total);
	}
	return 0;
}