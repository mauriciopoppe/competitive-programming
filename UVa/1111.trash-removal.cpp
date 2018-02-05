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

vector<Point> ConvexHull(vector <Point> P) {
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

int main() {
	int n;
	int cas = 1;
	while (cin >> n && n) {
		vector<Point> p(n);
		F(i, n) cin >> p[i].x >> p[i].y;
		p = ConvexHull(p);
		n = p.size();
		double mn = 1e18;
		F(i, n) {
			Point p1 = p[i];
			Point p2 = p[(i + 1) % n];
			double mx = 0;
			for (int j = (i + 1) % n; j != i; j = (j + 1) % n) {
				double base = proyectionTimesModule(p1, p2, p[j]) / (p2 - p1).mod();
				// double hyp = dist(p1, p[j]);
				mx = max(mx, sqrt((p[j] - p1).mod2() - base * base));
			}
			mn = min(mn, mx);
		}

		mn *= 100;
		mn = ceil(mn);
		mn /= 100;
		printf("Case %d: %.2lf\n", cas++, mn);
	}
	return 0;
}