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
#include <cassert>
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
#define EPS 1e-7
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
typedef vector<Point> vp;

Point operator +(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
Point operator /(const Point &a, double k) { return Point(a.x/k, a.y/k); }
Point operator *(const Point &a, double k) { return Point(a.x*k, a.y*k); }

bool operator ==(const Point &a, const Point &b) {
	return fabs(a.x - b.x) < EPS && fabs(a.y - b.y) < EPS;
}
bool operator !=(const Point &a, const Point &b) {
	return !(a==b);
}
bool operator <(const Point &a, const Point &b) {
	if(a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

double dist(const Point &A, const Point &B)    { return hypot(A.x - B.x, A.y - B.y); }
double cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; }
double dot(const Vector &A, const Vector &B)   { return A.x * B.x + A.y * B.y; }

double proyectionTimesModule(const Point &A, const Point &B, const Point &C) { return dot(B - A, C - A); }
double area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }

bool isParallel(const Point &P1, const Point &P2, const Point &P3, const Point &P4) {
	return cross(P2 - P1, P4 - P3) == 0;
}

Point lineIntersection(const Point &A, const Point &B, const Point &C, const Point &D) {
	return A + (B - A) * (cross(C - A, D - C) / cross(B - A, D - C));
}

void print(vp &p) {
	TR(p, it) printf("(%.0lf, %.0lf) - ", it->x, it->y); NL;			
}

void printp(Point &p) { printf ("(%lf, %lf)\n", p.x, p.y);}

double area(const vector <Point> &P) {
	int n = P.size();
	double A = 0;
	for(int i=1; i<=n-2; i++)
		A += area(P[0], P[i], P[i+1]);
	return abs(A/2);
}

vp cut_polygon(Point p1, Point p2, vp &p) {
	int n = p.size();
	vp ans;
	for (int i = 0; i < n; i += 1) {
		Point v1 = p[i], v2 = p[(i + 1) % n];
		double i1 =  area(p1, p2, v1);
		double i2 =  area(p1, p2, v2);

		if (i1 >= 0) ans.push_back(v1);
		if (i1 * i2 < 0) ans.push_back(lineIntersection(v1, v2, p1, p2));
	}
	return ans;
}

Point fountain;
int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int n, W, H;
	Point p1, p2;
	int cas = 1;
	while (cin >> n >> W >> H >> fountain.x >> fountain.y) {
		vp p;
		p.push_back(Point(0, 0));
		p.push_back(Point(W, 0));
		p.push_back(Point(W, H));
		p.push_back(Point(0, H));
		F(i, n) {
			cin >> p1.x >> p1.y >> p2.x >> p2.y;
			if (area(p1, p2, fountain) > 0) {
				p = cut_polygon(p1, p2, p);
			} else {
				p = cut_polygon(p2, p1, p);
			}
		}
		printf("Case #%d: %.3lf\n", cas++, area(p));
	}
	return 0;
}