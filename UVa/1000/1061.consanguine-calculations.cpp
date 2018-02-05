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
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<string> vs;

map<string, string> bt;
map<string, string> rev;
int cas;

void print_solution(vs sol) {
	if (sol.size() == 0) {
		printf("IMPOSSIBLE");
		return;
	}

	if (sol.size() > 1) {
		printf("{");
	}

	F(i, sol.size()) {
		if (i) printf(", ");
		printf("%s", sol[i].c_str());
	}

	if (sol.size() > 1) {
		printf("}");
	}	
}

vs gen_possible(string a, string b) {
	int s1 = a.size(), s2 = b.size();
	char f1 = a[s1 - 1], f2 = b[s2 - 1];

	string bt1 = bt[a.substr(0, s1 - 1)];
	string bt2 = bt[b.substr(0, s2 - 1)];

	set<string> s;
	F(i, bt1.size())
		F(j, bt2.size()) {
			char c1 = bt1[i], c2 = bt2[j];
			if (c2 < c1) swap(c1, c2);
			stringstream ss;
			ss << c1 << c2;
			string k = ss.str();
			// cout << rev[k] << endl;
			s.insert(rev[k]);
		}

	vs sol;
	TR(s, it) {
		if (f1 == '-' && f2 == '-') {
			sol.push_back(*it + "-");
		} else {
			sol.push_back(*it + "-");
			sol.push_back(*it + "+");
		}
	}
	return sol;	
}

void solveChild(string a, string b, string c) {
	vs sol = gen_possible(a, b);
	printf("Case %d: %s %s ", cas++, a.c_str(), b.c_str());
	print_solution(sol);
	NL;
}

void solveParent(string a, string b, string c) {
	vs sol;

	int r = 0;
	if (a == "?") r = 1, swap(a, b);
	

	vs signs;
	signs.push_back("+");
	signs.push_back("-");
	TR(bt, it) {
		string k = it->first;
		F(i, signs.size()) {
			vs possible = gen_possible(a, k + signs[i]);
			vs::iterator it;
			it = find(possible.begin(), possible.end(), c);
			if (it != possible.end()) {
				sol.push_back(k + signs[i]);
				// printf("%s\n", (k + signs[i]).c_str());
			}
		}
	}

	// printf("%d\n", r);
	if(r) swap(a, b);

	printf("Case %d: ", cas++);
	if (r) print_solution(sol);
	else printf("%s", a.c_str());
	putchar(' ');
	if (!r) print_solution(sol);
	else printf("%s", b.c_str());
	printf(" %s\n", c.c_str());
}

int main() {
	bt["A"] = "AO";
	bt["B"] = "BO";
	bt["AB"] = "AB";
	bt["O"] = "O";

	rev["AA"] = "A";
	rev["AB"] = "AB";
	rev["AO"] = "A";
	rev["BB"] = "B";
	rev["BO"] = "B";
	rev["OO"] = "O";

	string p1, p2, c;
	cas = 1;
	while (cin >> p1 >> p2 >> c) {
		if (p1 == "E") break;
		if (p1 == "?" || p2 == "?") solveParent(p1, p2, c);
		else solveChild(p1, p2, c);
	}
	return 0;
}