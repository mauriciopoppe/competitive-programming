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

#define Vector Point
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

Point operator +(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
Point operator /(const Point &a, double k) { return Point(a.x/k, a.y/k); }
Point operator *(const Point &a, double k) { return Point(a.x*k, a.y*k); }

double dist(const Point &A, const Point &B)    { return hypot(A.x - B.x, A.y - B.y); }
double cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; }
double dot(const Vector &A, const Vector &B)   { return A.x * B.x + A.y * B.y; }
double area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }
double triangleArea(const Point &a, const Point &b, const Point &c) { return abs(area(a, b, c)) * 0.5; }

Point lineIntersection(const Point &A, const Point &B, const Point &C, const Point &D) {
	return A + (B - A) * (cross(C - A, D - C) / cross(B - A, D - C));
}

double segmentToPointDistance(const Point &a, const Point &b, const Point &p) {
	Point norm = (b - a).unit();
	double reflection = dot(p - a, norm);
	// beyond ab
	if (reflection >= dist(a, b)) return dist(p, b);
	// beyond ba
	if (reflection < 0) return dist(p, a);
	// line - line intersection
	Point q = p + (b - a).ort();
	return dist(lineIntersection(a, b, p, q), p);
}

int main() {
	// freopen("in", "r", stdin);
	// freopen("out", "w", stdout);

	int cas;
	cin >> cas;
	while(cas--) {
		vector<Point> t(3);
		Point circle;
		double radius;
		F(i, 3) cin >> t[i].x >> t[i].y;
		cin >> circle.x >> circle.y >> radius;

		int solved = 0;
		double total_area = 0;
		// circle - segment intersection
		F(i, 3) {
			double d = segmentToPointDistance(t[i], t[(i + 1) % 3], circle);
			total_area += triangleArea(t[i], t[(i + 1) % 3], circle);
			solved |= (d <= radius);
		}
		// point in triangle
		solved |= ( abs(total_area - triangleArea(t[0], t[1], t[2])) < EPS );
		printf("%s\n", solved ? "YES" : "NO");
	}
	return 0;
}