#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  ll r, c;
  while (cin >> r >> c) {
    if (r == 0 && c == 0) break;
    if (r > c) swap(r, c);
    ll total = 0;
    // vert/hor
    total += r * c * (c - 1 + r - 1);
    // full diag
    total += 2 * (c - r + 1) * r * (r - 1);
    // incremental diagonals
    total += 2 * (2 * r * (r - 1) * (r - 2) / 3);

    printf("%llu\n", total);
  }
}
