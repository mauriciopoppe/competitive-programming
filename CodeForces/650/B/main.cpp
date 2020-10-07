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
  cin.exceptions(cin.failbit);
  int t;
  cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> md;
    int k1 = 0, k2 = 0;
    for (int i = 0; i < n; i += 1) {
      int k;
      cin >> k;
      md.push_back(k % 2);
      if (i % 2 == 0 && k % 2 == 1) k1++;
      if (i % 2 == 1 && k % 2 == 0) k2++;
    }
    if (k1 != k2) cout << -1 << endl;
    else cout << k1 << endl;
  }
  return 0;
}
