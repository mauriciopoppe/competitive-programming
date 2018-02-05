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
#include <climits>
#include <cfloat>
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
#define TR(ar, it) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;


#define EPS 1e-8
#define PI acos(-1)
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

//### BASIC FUNCTIONS

double dist(const Point &A, const Point &B)    { return hypot(A.x - B.x, A.y - B.y); }
double cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; }
double dot(const Vector &A, const Vector &B)   { return A.x * B.x + A.y * B.y; }

double proyectionTimesModule(const Point &A, const Point &B, const Point &C) { return dot(B - A, C - A); }
double area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }

vector <Point> ConvexHull(vector <Point> P) {
	sort(P.begin(),P.end());
	int n = P.size(),k = 0;
	Point *H = new Point[2*n];

	for(int i=0;i<n;++i){
		while(k>=2 && area(H[k-2],H[k-1],P[i]) <= 0) --k;
		H[k++] = P[i];
	}

	for(int i=n-2,t=k;i>=0;--i){
		while(k>t && area(H[k-2],H[k-1],P[i]) <= 0) --k;
		H[k++] = P[i];
	}

	return vector <Point> (H,H+k-1);
}

Point rotate(Point &p, double angle) {
	return Point(
		p.x * cos(angle) - p.y * sin(angle),
		p.x * sin(angle) + p.y * cos(angle)
	);
}

vector<Point> rotatePoints(vector<Point> &P, double degrees) {
	vector<Point> r;
	TR(P, it) r.push_back(rotate(*it, degrees));
	return r;
}

double f(vector<Point> &P, double degrees) {
	vector<Point> r = rotatePoints(P, degrees);
	double M = 1e10;
	double minx = M, maxx = -M, miny = M, maxy = -M;
	TR(r, it) {
		minx = min(minx, it->x);
		maxx = max(maxx, it->x);

		miny = min(miny, it->y);
		maxy = max(maxy, it->y);
	}
	return max(maxx - minx, maxy - miny);
}

int main() {
	int n;
	int cas; cin >> cas;
	while (cas--) {
		cin >> n;
		vector<Point> P(n);
		F(i, n) scanf("%lf%lf", &P[i].x, &P[i].y);
		P = ConvexHull(P);
		double lo = 0, hi = PI * 0.5;
		while (fabs(hi - lo) > 1e-8) {
			double mid1 = lo + (hi - lo) / 3.0;
			double mid2 = lo + (hi - lo) * 2.0 / 3.0;
			double f1 = f(P, mid1);
			double f2 = f(P, mid2);
			if (f1 <= f2) {
				hi = mid2;
			} else {
				lo = mid1;
			}
		}
		double ans = f(P, lo);
		printf("%.2lf\n", ans * ans);
	}

	return 0;
}
