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
#define EPS 1e-3
#define TR(ar, it) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define PI acos(-1)
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

//### BASIC FUNCTIONS
double dist(const Point &A, const Point &B)    { return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y); }
double cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; }

//### LINE INTERSECTION
Point lineIntersection(const Point &A, const Point &B, const Point &C, const Point &D) {
	return A + (B - A) * (cross(C - A, D - C) / cross(B - A, D - C));
}

int main() {
	vector<Point> c(3);	
	while(cin >> c[0].x >> c[0].y >> c[1].x >> c[1].y >> c[2].x >> c[2].y) {
		
		Point m1 = (c[0] + c[1]) / 2;
		Point m2 = (c[1] + c[2]) / 2;
		Point m1t = m1 + (c[1] - c[0]).ort();
		Point m2t = m2 + (c[2] - c[1]).ort();

		Point intersection = lineIntersection(m1, m1t, m2, m2t);

		printf("%.2lf\n", sqrt(dist(intersection, c[0])) * 2 * PI);
	}
	return 0;
}