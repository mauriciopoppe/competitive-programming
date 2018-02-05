#include <bits/stdc++.h>
using namespace std;

#define INF int(1e9)
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Point {
  double x, y;

  Point() {
    x = 0;
    y = 0;
  }

  Point(double _x, double _y) {
    x = _x;
    y = _y;
  }

  bool operator<(const Point &other) const {
    if (x != other.x) return x < other.x;
    return y < other.y;
  }

  bool operator==(const Point &other) const {
    return fabs(x - other.x) < 1e-2 &&
      fabs(y - other.y) < 1e-2;
  }

  bool operator!=(const Point &other) const {
    return !(*this == other);
  }

};

Point operator+(const Point &a, const Point &b) {
  return Point(a.x + b.x, a.y + b.y);
}

Point operator*(const Point &a, const double m) {
  return Point(a.x * m, a.y * m);
}

bool solve (vector<Point> &points, Point &center) {
  int n = points.size();
  rep(i, 0, n / 2 + 1) {
    Point a = points[i];
    Point b = points[n - i - 1];
    if ((a + b) * 0.5 != center) {
      return false;
    }
  }
  return true;
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int cas;
  cin >> cas;
  while (cas--) {
    int n;
    cin >> n;
    vector<Point> points(n);
    rep (i, 0, n) {
      cin >> points[i].x >> points[i].y;
    }
    sort(points.begin(), points.end());
    Point center = (points[0] + points[n - 1]) * 0.5;

    printf("%s\n", solve(points, center) ? "yes" : "no");
  }
}
