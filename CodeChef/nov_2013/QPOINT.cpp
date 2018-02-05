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
typedef vector<Point> vp;

struct AABB {
	Point origin;
	Point dim;
	int pi;
	AABB() {}
	AABB(Point _origin, Point _dim) {
		origin = _origin;
		dim = _dim;
	}
	double minX() { return origin.x; }
	double minY() { return origin.y; }
	double maxX() { return origin.x + dim.x; }	
	double maxY() { return origin.y + dim.y; }	
	double width() { return dim.x; }
	double height() { return dim.y; }
	bool contains(Point &p) {
		return origin.x <= p.x && origin.x + dim.x <= p.x &&
			origin.y <= p.y && p.y + dim.y <= p.y;
	}
	bool contains(AABB &p) {
		// print();
		// p.print();
		return origin.x <= p.origin.x && origin.x + dim.x >= p.origin.x &&
			   origin.y <= p.origin.y && origin.y + dim.y >= p.origin.y;
	}
	void print() {
		printf("(%.0lf, %.0lf) - (%.0lf, %.0lf)\n", minX(), minY(), maxX(), maxY());
	}
};

#define MXP 1
struct Quadtree {
	AABB bounds;
	// maps a point to a polygon index
	vector< pair<Point, int> > p;

	int objectsSize;
	vector<AABB> objects;

	vector<Quadtree> r;
	int level;
	bool hasChildren;

	Quadtree(AABB _bounds, int _level) {
		bounds = _bounds;
		level = _level;
		objectsSize = 0;
		hasChildren = false;
	}

	int getRegion(AABB &aabb) {
		// 01
		// 32
		int region = -1;
		Point mid = bounds.origin + (bounds.dim * 0.5);
		bool t = aabb.minY() > mid.y;
		bool b = aabb.minY() < mid.y && aabb.maxY() < mid.y;

		if (bounds.minX() < aabb.minX() && aabb.maxX() < mid.x) {
			// left
			if (t) region = 0;
			else if (b) region = 2;
		} else if(mid.x < aabb.minX() && aabb.maxX() < bounds.maxX()) {
			// right
			if (t) region = 1;
			else if (b) region = 3;
		}
		return region;
	}

	void split() {
		double x = bounds.minX();
		double y = bounds.minY();
		Point dim = bounds.dim * 0.5;
		r.push_back(Quadtree(AABB(Point(x, y + dim.y), dim), level + 1));
		r.push_back(Quadtree(AABB(Point(x + dim.x, y + dim.y), dim), level + 1));
		r.push_back(Quadtree(AABB(Point(x + dim.x, y), dim), level + 1));
		r.push_back(Quadtree(AABB(Point(x, y), dim), level + 1));
	}

	AABB remove(int index) {
		AABB aabb = objects[index];
		objects.erase(objects.begin() + index);
		objectsSize--;
		return aabb;
	}

	void insert(AABB aabb) {
		if (hasChildren) {
			int region = getRegion(aabb);
			if (region != -1) {
				r[region].insert(aabb);
				return;
			}
		}
		objects.push_back(aabb); objectsSize++;

		// split the node if exceeds MXP
		if (objectsSize > MXP) {
			if (!r.size()) split();
			int i = 0;
			while (i < objectsSize) {
				int index = getRegion(objects.front());
				if (index != -1) r[index].insert(remove(i));
				else ++i;
			}
		}
	}

	vi query(AABB &p) {
		vi aabb;
		// printf("%d s=%d\n", level, objectsSize);
		F(i, objectsSize) {
			if (objects[i].contains(p)) {
				aabb.push_back(objects[i].pi);			
			}
		}
		if (hasChildren) {
			// printf("has children!");
			int index = getRegion(p);
			vi in = r[index].query(p);
			aabb.insert(aabb.end(), ALL(in));
		}
		return aabb;
	}
};

AABB make_aabb(vp &p, int i) {
	double minX = 1e10, minY = 1e10, maxX = -1, maxY = -1;
	TR(p, it) {
		minX = min(minX, it->x);
		maxX = max(maxX, it->x);
		minY = min(minY, it->y);
		maxY = max(maxY, it->y);
	}
	AABB aabb = AABB(Point(minX, minY), Point(maxX - minX, maxY - minY));
	// printf("%lf,%lf - %lf,%lf\n", aabb.minX(), aabb.minY(), aabb.maxX(), aabb.maxY());
	aabb.pi = i;
	return aabb;
}

double cross(const Point &A, const Point &B) { return A.x * B.y - A.y * B.x; }
double area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }

bool pointInPoly(const vector <Point> &P, const Point &A) {
	int n = P.size(), cnt = 0;
	for(int i=0; i<n; i++) {
		int inf = i, sup = (i+1)%n;
		if(P[inf].y > P[sup].y) swap(inf, sup);
		if(P[inf].y <= A.y && A.y < P[sup].y)
			if(area(A, P[inf], P[sup]) >= 0)
				cnt++;
	}
	return (cnt % 2) == 1;
}

vector<vp> polygons;
void solve(Quadtree &root, AABB &q) {
	vi possible = root.query(q);
	TR(possible, it) {
		// printf("testing %d\n", *it);
		if (pointInPoly(polygons[*it], q.origin)) {
			printf("%d\n", *it + 1);
			return;
		}
	}
	puts("-1");
}

int main() {
	// freopen("in", "r", stdin);
	// freopen("out", "w", stdout);
	
	int n, nPoints, nQ;
	Point q;
	while(cin >> n) {
		AABB bounds(Point(0, 0), Point(1e9, 1e9));
		Quadtree root(bounds, 0);
		polygons.clear();
		// vector<vp> polygons;
		F(i, n) {
			scanf("%d", &nPoints);
			vp p(nPoints);
			F(j, nPoints) scanf("%lf%lf", &p[j].x, &p[j].y);
			polygons.push_back(p);
			root.insert(make_aabb(p, i));
		}
		// puts("END");
		scanf("%d", &nQ);
		F(z, nQ) {
			scanf("%lf%lf", &q.x, &q.y);
			AABB aabb(q, Point(0, 0));
			solve(root, aabb);
		}
	}
	return 0;
}