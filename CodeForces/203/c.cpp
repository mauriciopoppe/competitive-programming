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
#define p2(x) ((x)*(x))
struct point {
	int x, y;
	int d;
	point() { x = 0; y = 0; }
	point(int _x, int _y) { x = _x; y = _y; }

	void calculate_distance() {
		d = abs(x) + abs(y);
	}

	bool operator<(const point &other) const {
		return d < other.d;
	}
};

vector<string> sol;
char s[1000];

void move(point start, point end) {
	if (start.x == end.x) {
		if (start.y < end.y) sprintf(s, "1 %d U", (int)abs(start.y - end.y));
		if (start.y > end.y) sprintf(s, "1 %d D", (int)abs(start.y - end.y));
	} else if (start.y == end.y) {
		if (start.x < end.x) sprintf(s, "1 %d R", (int)abs(start.x - end.x));
		if (start.x > end.x) sprintf(s, "1 %d L", (int)abs(start.x - end.x));
	}
	sol.push_back((string)s);
}

void solve_move(point start, point &end) {
	if (start.x == end.x || start.y == end.y) {
		move(start, end);
		sol.push_back("2");
		move(end, start);
	} else {
		point mid = point(start.x, end.y);
		move(start, mid);
		move(mid, end);
		sol.push_back("2");
		move(end, mid);
		move(mid, start);
	}
	sol.push_back("3");
}

int main() {
	int n;
	while(cin >> n) {
		vector<point> p(n);
		F(i, n) {
			cin >> p[i].x >> p[i].y;
			p[i].calculate_distance();
		}
		sort(ALL(p));
		sol.clear();
		F(i, n) {
			solve_move(point(0, 0), p[i]);
		}
		
		printf("%d\n", (int)sol.size());
		TR(sol, it) cout << *it << endl;
	}
	return 0;
}