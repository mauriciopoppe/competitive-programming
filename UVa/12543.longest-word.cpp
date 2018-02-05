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

int main() {
	int mx = 0;
	string s, best = "";
	while (cin >> s && s != "E-N-D") {
		string k = "";
		for (int i = 0; s[i]; i += 1) {
			if (!(isalpha(s[i]) || s[i] == '-')) k += " ";
			else k += s[i];
		}
		stringstream ss(k);
		string buf;
		while (ss >> buf) {
			if (buf.size() > mx) {
				mx = (int)buf.size();
				best = buf;
			}
		}
	}
	
	for(int i = 0; best[i]; i += 1) {
		if (isalpha(best[i])) cout << (char)tolower(best[i]);
		else cout << best[i];
	}
	NL;
	return 0;
}