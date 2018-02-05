#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Point {
public: 
	double x, y;
	Point(double _x, double _y) {
		x = _x;
		y = _y;
	}
};

double dist(Point a, Point b) {
	return sqrt(
		(a.x - b.x) * (a.x - b.x) +
		(a.y - b.y) * (a.y - b.y)
	);
}

bool xy(Point &a, Point &b) {
	if (a.x != b.x) {
		return a.x < b.x;
	}
	return a.y < b.y;
}

bool yx(Point &a, Point &b) {
	if (a.y != b.y) {
		return a.y < b.y;
	}
	return a.x < b.x;
}

double closest_recursive(vector<Point> &sx, vector<Point> &sy) {
	int n = sx.size();

	if (n == 1) return 1e20;
	if (n == 2) return dist(sx[0], sx[1]);

	Point mid = sx[n / 2];

	// create the set of y-sorted points to the left
	// and right of the middle vertical line
	vector<Point> yLeft, yRight;
	for (int i = 0; i < n; i += 1) {
		if (sy[i].x <= mid.x) {
			yLeft.push_back(sy[i]);
		} else {
			yRight.push_back(sy[i]);
		}
	}

	// the sx needs to be recreated for each side
	vector<Point> xLeft, xRight;
	for (int i = 0; i < n; i += 1) {
		if (sx[i].x <= mid.x) {
			xLeft.push_back(sx[i]);
		} else {
			xRight.push_back(sx[i]);
		}
	}

	double distance_left = closest_recursive(xLeft, yLeft);
	double distance_right = closest_recursive(xRight, yRight);
	double d = min(distance_left, distance_right);

	// build the strip and find the min distance there
	vector<Point> strip;
	for (int i = 0; i < sy.size(); i += 1) {
		if (abs(sy[i].x - mid.x) <= d) {
			strip.push_back(sy[i]);
		}
	}

	for (int i = 0; i < strip.size(); i += 1) {
		for (int j = i + 1; j < strip.size() && strip[j].y - strip[i].y <= d; j += 1) {
			d = min(d, dist(strip[i], strip[j]));
		}
	}
	return d;
}

double closest_line(vector<Point> p) {
	vector<Point> sx = p, sy = p;
	sort(sx.begin(), sx.end(), xy);
	sort(sy.begin(), sy.end(), yx);
	return closest_recursive(sx, sy);
}

int main() {
	vector<Point> p;
	p.push_back(Point(2, 3));
	p.push_back(Point(12, 30));
	p.push_back(Point(40, 50));
	p.push_back(Point(5, 1));
	p.push_back(Point(12, 10));
	p.push_back(Point(3, 4));
	cout << closest_line(p);
}