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

  int cas;
  cin >> cas;
  while (cas--) {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    s = "1" + string(max(k, 1), '0') + s + string(max(k, 1), '0') + "1";
    // cout << s << endl;
    int prev = -1;
    int total = 0;
    for (int i = 0; i < s.size(); i += 1) {
      if (s[i] == '1' && prev != -1) {
        int left = i - prev - 1;
        left -= 2 * k;
        left = max(left, 0);
        if (left) {
          total += 1 + (left - 1) / (k + 1);
        }
      }
      if (s[i] == '1') prev = i;
    }
    cout << total << endl;
  }
}
