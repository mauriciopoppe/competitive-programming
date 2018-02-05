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

vi kmp(string t, string p) {
	int i, pos;
	vi b(p.size() + 1, -1);
	for (i = 1; i <= p.size(); i += 1) {
		pos = b[i - 1];
		while (pos >= 0 && p[pos] != p[i - 1])
			pos = b[pos];
		b[i] = pos + 1;
	}

	vi matches;
	for (i = 0, pos = 0; i < t.size(); i += 1) {
		while(pos >= 0 && (pos == p.size() || p[pos] != t[i]))
			pos = b[pos];
		pos++;
		if (pos == p.size())
			matches.push_back(i - pos + 1);
	}
	return matches;
}


int main() {
	string t, p;
	while(cin >> t >> p) {
		vi matches = kmp(t, p);
		TR(matches, it) printf("%d ", *it); NL;
	}
	return 0;
}