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

//### LINE INTERSECTION
Point lineIntersection(const Point &A, const Point &B, const Point &C, const Point &D) {
	return A + (B - A) * (cross(C - A, D - C) / cross(B - A, D - C));
}

// O(n log n)
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

// rotating calipers
double rotating_calipers(vector<Point> &P) {
	int n = P.size();

	double minArea = DBL_MAX;
	for (int i = 0, j = 2, k = 1, l = -1; i < n; i += 1) {
		while (area(P[i], P[(i + 1) % n], P[(j + 1) % n]) > area(P[i], P[(i + 1) % n], P[j])) {
			j = (j + 1) % n;
		}
		// Par antipodal: i, j
		// Par antipodal: (i + 1) % n, j

		while (proyectionTimesModule(P[i], P[(i + 1) % n], P[(k + 1) % n]) >
			proyectionTimesModule(P[i], P[(i + 1) % n], P[k])) {
			k = (k + 1) % n;
		}

		if (l == -1) l = j;
		while (proyectionTimesModule(P[i], P[(i + 1) % n], P[(l + 1) % n]) <
			proyectionTimesModule(P[i], P[(i + 1) % n], P[l])) {
			l = (l + 1) % n;
		}

		// enclosing rectangle:
		// bottom = (i, i + 1 % n)
		// top = j
		// right = k
		// left = l
		// printf("bottom=%d top=%d right=%d left=%d\n", i, j, k, l);

		// project k and l over (i, (i + 1) % n)
		
		// abs(cross) / 2 = A
		// A = b * h / 2
		// abs(cross) / 2 = b * h / 2
		// h = abs(cross) / b
		double height = abs(area(P[i], P[(i + 1) % n], P[j])) / dist(P[i], P[(i + 1) % n]);
		Vector base = P[(i + 1) % n] - P[i];
		double width = dot(base.unit(), P[k] - P[i]) - dot(base.unit(), P[l] - P[i]);

		minArea = min(minArea, width * height);
	}

	return minArea;
}

int main() {
	int n;
	while (cin >> n && n) {
		vector<Point> P(n);
		F(i, n) scanf("%lf%lf", &P[i].x, &P[i].y);
		if (n <= 2) {
			puts("0.0000");
			continue;
		}
		vector<Point> cv = ConvexHull(P);
		// TR(cv, it) printf(" | %lf %lf", it->x, it->y); NL;
		printf("%.4lf\n", rotating_calipers(cv));
	}

	return 0;
}
