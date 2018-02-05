#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define MS(a, v) memset(a, v, sizeof a)
#define NL printf("\n")
#define INF 1e9
#define PI acos(-1)
#define EPS 1e-9
#define TR(ar, it) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )

typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> merge(vector<int> &a, vector<int> &b) {
	int i = 0, j = 0;
	vector<int> c;
	while (i < a.size() && j < b.size()) {
		if (a[i] == b[j]) {
			c.push_back(a[i]);
			++i, ++j;
		} else if (a[i] > b[j]) {
			++j;
		} else {
			++i;
		}
	}

	// 2 3 4 4 4 5
	vector<int> c_without_dup;
	for (i = 0; i < c.size() - 1; i += 1) {
		if (c[i] != c[i + 1]) {
			c_without_dup.push_back(c[i]);
		}
	}
	c_without_dup.push_back(c[c.size() - 1]);

	for (int n: c_without_dup) {
		cout << n << " ";
	}
	cout << endl;

	return c_without_dup;
}

int main() {
	int a[] = {1, 2, 3, 3, 4, 4, 5};
	vector<int> va(a, a + 7);
	int b[] = {3, 3, 3, 4, 6, 6, 7};
	vector<int> vb(b, b + 7);
	merge(va, vb);
	return 0;
}