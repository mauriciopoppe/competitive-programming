#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct State {
  int gcd;
  int h;
  int x;
  int y;

  State(int _gcd, int _x, int _y, int _h) {
    gcd = _gcd;
    h = _h;
    x = _x;
    y = _y;
  }

  bool operator<(const State &other) const {
    return gcd < other.gcd;
  }
};

int GCD(int a, int b) {
  // special case
  if (a == 0) return b;
  if (b == 0) return a;
  return GCD(b, a % b);
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int n;
  int cnt = 1;
  while (cin >> n && n) {
    map<pii, vector<State>> points;

    int x, y, h;
    rep(i, 0, n) {
      cin >> x >> y >> h;
      int gcd = GCD(abs(x), abs(y));
      // assert(gcd > 0);
      points[{x / gcd, y / gcd}].push_back(State(gcd, x, y, h));
    }

    vector<pii> blocked;
    trav (it, points) {
      vector<State> &t = it.second;
      sort(t.begin(), t.end());
      int mx = t[0].h;
      for (int i = 1; i < t.size(); i += 1) {
        if (t[i].h <= mx) {
          blocked.push_back({ t[i].x, t[i].y });
        }
        mx = max(mx, t[i].h);
      }
    }

    printf("Data set %d:\n", cnt++);
    if (!blocked.size()) {
      printf("All the lights are visible.\n");
    } else {
      sort(blocked.begin(), blocked.end());
      printf("Some lights are not visible:\n");
      rep(i, 0, blocked.size()) {
        pii it = blocked[i];
        printf("x = %d, y = %d%s\n",
            it.first, it.second, i == blocked.size() - 1 ? "." : ";");
      }
    }
  }

}
