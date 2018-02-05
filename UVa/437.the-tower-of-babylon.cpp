#include <bits/stdc++.h>
#define INF int(1e9*2)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

class Box {
public:
  int x, y, z;
  int sum;
  Box(){}
  Box(int _x, int _y, int _z) {
    x = min(_x, min(_y, _z));
    z = max(_x, max(_y, _z));
    // !
    y = _x + _y + _z - x - z;
    sum = x + y + z;
  }
};

vector<Box> boxes;
map<pii, int> dp;

int solve(int x, int y) {
  pii state = {x, y};
  if (dp.find(state) != dp.end()) return dp[state];
  int best = 0;
  for (int i = 0; i < boxes.size(); i++) {
    Box box = boxes[i];
    vector<pii> v = {{box.x, box.y}, {box.x, box.z}, {box.y, box.z}};
    for (int j = 0; j < 3; j++) {
      pii cur = v[j];
      if (x > cur.first && y > cur.second) {
        best = max(best, solve(cur.first, cur.second) +
            box.sum - cur.first - cur.second);
      }
    }
  }
  return dp[state] = best;
}

int main() {
  int n;
  int cas = 1;
  while (cin >> n && n) {
    boxes.resize(n);
    dp.clear();
    int x, y, z;
    for (int i = 0; i < n; i += 1) {
      cin >> x >> y >> z;
      boxes[i] = Box(x, y, z);
    }
    printf("Case %d: maximum height = %d\n", cas++, solve(INF, INF));
  }
}
