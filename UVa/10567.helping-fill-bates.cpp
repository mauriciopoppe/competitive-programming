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

vector<int> lower[26];
vector<int> upper[26];
map<char, int> lowestIndex;

string text;
int aSize;
int isLower(char w) {
	return w >= 'a' && w <= 'z';
}
void process(string w) {
	aSize = w.size();
	F(i, aSize) {
		if (w[i] <= 'Z') upper[w[i] - 'A'].push_back(i);
		else lower[w[i] - 'a'].push_back(i);
	}
}

int binarySearch(vector<int> &A, int lo, int hi, int k) {
	if (hi < 1 || A[hi] <= k) return -1;
	while (hi - lo > 1) {
		int m = lo + (hi - lo) / 2;
		if (A[m] > k) hi = m;
		else lo = m;
	}
	// printf("hi = %d\n", hi);
	return A[hi];
}

int first, last;
int solve(string &q) {
	first = -1;
	last = -1;

	int start = -1;
	F(i, q.size()) {
		vi *v;
		if (isLower(q[i])) {
			v = &lower[q[i] - 'a'];
		} else {
			v = &upper[q[i] - 'A'];
		}

		// F(i, v->size()) printf("%d ", (*v)[i]); NL; 
		int mn = binarySearch(*v, -1, v->size() - 1, start);
		// printf("%c = %d\n", q[i], mn);
		if (mn == -1) return false;
		if (first == -1) first = mn;
		start = mn;
		last = mn;
	}
	return true;
}
int main() {
	
	cin >> text;
	process(text);

	int n;
	cin >> n;
	while (n--) {
		string q;
		cin >> q;
		if (solve(q)) printf("Matched %d %d\n", first, last);
		else printf("Not matched\n");
	}
	return 0;
}