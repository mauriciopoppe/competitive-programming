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

set<string> T, L;
map<string, string> table;

void print_sep() {
	int size = T.size() + 1;
	F(i, size) printf("+---");
	printf("+\n");
}

int main() {
	// freopen("in", "r", stdin);
	// freopen("out", "w", stdout);
	
	int cas;
	string a, b, c;
	cin >> cas;
	F(z, cas) {
		int n; cin >> n;
		T.clear();
		L.clear();
		table.clear();
		F(i, n) {
			cin >> a >> b >> c;
			L.insert(a);
			T.insert(b);
			table[a + ',' + b] = c;
		}

		print_sep();
		printf("|   |");
		TR(T, it) printf("%-3s|", it->c_str()); NL;
		print_sep();
		TR(L, it) {
			printf("|%-3s|", it->c_str());
			TR(T, it2) {
				string exists = "   ";
				if (table.find(*it + ',' + *it2) != table.end())
					exists = table[*it + ',' + *it2];
				printf("%-3s|", exists.c_str());
			}
			NL;
			print_sep();
		}
	}

	return 0;
}