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
#define PI acos(-1)
struct Point {
	double x, y;
	Point(){}
	Point(double a, double b) { x = a; y = b; }
	double mod2() { return x*x + y*y; }
	double mod()  { return sqrt(x*x + y*y); }
	double arg()  { return atan2(y, x); }
	Point ort()   { return Point(-y, x); }
	Point unit()  { double k = mod(); return Point(x/k, y/k); }
};
Point operator *(const Point &a, double k) { return Point(a.x*k, a.y*k); }
Point operator +(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }

Point rotate(const Point &p, double angle) {
	return Point(
		p.x * cos(angle) - p.y * sin(angle),
		p.x * sin(angle) + p.y * cos(angle)
	);
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		int r;
		cin >> r;
		Point m(0, 0);
		Point d(1, 0);
		F(i, r) {
			string s;
			double u;
			cin >> s >> u;
			if (s == "fd") {
				m = m + d * u;
			} else if (s == "lt") {
				d = rotate(d, u * PI / 180.0);
			} else if (s == "rt") {
				d = rotate(d, -u * PI / 180.0);
			} else {
				m = m + d * (-u);
			}
		}
		printf("%d\n", (int) round(m.mod()));
	}
	return 0;
}