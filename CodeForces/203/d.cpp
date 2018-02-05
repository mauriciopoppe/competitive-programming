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
typedef pair<double, double> pii;
typedef vector<int> vi;
#define Vector Point
typedef long long LL;

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

double dot(const Vector &A, const Vector &B)   { return A.x * B.x + A.y * B.y; }
double dist(const Point &A, const Point &B)    { return hypot(A.x - B.x, A.y - B.y); }
double cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; }

//### LINE INTERSECTION
Point lineIntersection(const Point &A, const Point &B, const Point &C, const Point &D) {
	return A + (B - A) * (cross(C - A, D - C) / cross(B - A, D - C));
}

double getAngleWithX(Point a, Point b) {
	if (b.y < a.y) swap(a, b);
	Point n = (b - a).unit();
	Point x = Point(1, 0);
	return acos(dot(n, x) / x.mod());
}

double distToOrigin(Point &a, Point &b) {
	Point oa(0, 0), ob(1, 0);
	Point ip = lineIntersection(a, b, oa, ob);
	return dist(oa, ip) * ip.x >= 0 ? 1 : -1;
}

int main() {
	int n, m;
	Point p1, p2;
	while (cin >> n >> m) {
		map<pii, vector<int> > a;

		vector<Point> sa(n);
		vector<Point> sb(n);
		F(i, n) {
			scanf("%lf%lf%lf%lf\n", &p1.x, &p1.y, &p2.x, &p2.y);
			pii p(getAngleWithX(p1, p2), distToOrigin(p1, p2));
			if (a.find(p) == a.end()) {
				a[p] = vector<int>();
			}
			sa[i] = p1; sb[i] = p2;
			a[p].push_back(i);
		}

		vector<Point> c(m);
		vector<double> r(m);
		F(i, m) {
			scanf("%lf%lf%lf", &c[i].x, &c[i].y, &r[i]);			
		}

		int total = 0;
		F(i, m) {
			for (int j = i + 1; j < m; j += 1) {
				if (r[i] != r[j]) continue;
				if (dist(c[i], c[j]) <= r[i] + r[j]) continue;

				Point mid = (c[i] + c[j]) / 2;
				Point mOrt = (c[i] - c[j]).ort() + mid;
				pii p(getAngleWithX(mid, mOrt), distToOrigin(mid, mOrt));
				TR(a[p], it) {
					Point p1 = sa[*it];
					Point p2 = sb[*it];
					// printf("%lf %lf\n", mid.x, mid.y);
					if (max(p1.x, p2.x) >= mid.x && min(p1.x, p2.x) <= mid.x && 
						max(p1.y, p2.y) >= mid.y && min(p1.y, p2.y) <= mid.y) {
						total++;
					}
				}
			}
		}
		printf("%d\n", total);
	}
	return 0;
}