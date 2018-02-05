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

void convert_base(int from, string str, int to) {
	// from -> base 10 conversion
	int dec = 0;
	int power = 1;
	for (int i = str.size() - 1; i >= 0; i -= 1) {
		dec = dec + power * (isdigit(str[i]) ? str[i] - '0' : str[i] - 'A' + 10);
		power *= from;
	}

	cout << static_cast<int> ("4") * 4 << endl;

	// cout << dec << endl;

	// from base 10 to the base `to`
	stringstream ss;
	while (dec) {
		int rem = dec % to;
		if (rem < 10) {
			ss << rem;
		} else {
			ss << static_cast<char>(rem - 10 + 'A');	
		}
		// ss << ":" << (rem > 10 ? (char)static_cast<char>(rem - 10 + 'A') : rem);
		dec /= to;
	}
	string res = ss.str();
	reverse(res.begin(), res.end());
	cout << res << endl;
}

int main() {
	convert_base(16, "FF", 16);
	return 0;
}