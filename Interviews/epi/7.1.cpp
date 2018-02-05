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

int stringToInt(string s) {
	int mult = 1;
	int res = 0;
	int i = 0;
	if (s[i] == '-') {
		++i;
		mult = -1;
	}
	for (; s[i]; i += 1) {
		if (isdigit(s[i])) {
			res = res * 10 + s[i] - '0';
		} else {
			throw string("not a valid integer");
		}
	}
	return res * mult;
}

int main() {
	cout << stringToInt("-10") * 1 << endl;
	cout << stringToInt("12341234") * 1 << endl;
	try {
		stringToInt("-10ad");
	} catch (string e) {
		cout << e << endl;
	}
	return 0;
}