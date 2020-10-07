#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.sync_with_stdio(0); cin.tie(0);

  int n;
  while (cin >> n) {
    int h = 2;
    int w = n / h;

    vector<pair<int,int>> out;

    if (n == 1) {
      printf("5\n0 0\n-1 0\n1 0\n0 1\n0 -1\n");
      continue;
    }


    out.push_back({-1, 0});
    out.push_back({-1, 1});
    // printf("-1 0\n");
    // printf("-1 1\n");

    for (int i = 0; i < w; i += 1) {
      out.push_back({i, -1});
      out.push_back({i, 2});
    }

    for (int x = 0; x < w; x += 1) {
      for (int y = 0; y < h; y += 1) {
        out.push_back({ x, y });
        // printf("%d %d\n", x, y);
      }
    }

    out.push_back({w, 0});
    out.push_back({w, 1});

    // printf("%d 0\n", w);
    // printf("%d 1\n", w);
    if (n % 2 != 0) {
      out.push_back({ w, 2 });
      out.push_back({ w+1, 1 });
      // printf("%d 2\n", w);
      // printf("%d 1\n", w+1);
    }

    printf("%d\n", (int) out.size());
    for (auto p: out) {
      printf("%d %d\n", p.first, p.second);
    }
  }
}
