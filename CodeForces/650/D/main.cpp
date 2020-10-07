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
    string s; cin >> s;
    int m; cin >> m;
    vector<pair<int, int>> a;
    vector<int> A;
    for (int i = 0; i < m; i += 1) {
      int k; cin >> k;
      A.push_back(k);
      a.push_back({k, i});
    }
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    sort(a.begin(), a.end());

    string ans;

    vector<bool> taken(s.size());

    function<void(string, string&, char)> dfs = [&](string s, string &out, char last) {
      if (ans.size() != 0) return;

      // cout << out << endl;

      int total = 0;
      for (int i = 0; i < m; i += 1) {
        if (out[i] != ' ') ++total;
      }
      if (total == m) {
        ans = out;
        return;
      }

      for (int k = 0; k < s.size(); k += 1) {
        char ch = s[k];
        if (taken[k] || (last != ' ' && last < ch)) continue;
        for (int i = 0; i < m; i += 1) {
          int total = 0;
          if (out[i] != ' ') continue;
          for (int j = 0; j < m; j += 1) {
            if (out[j] != ' ' && out[j] > ch) total += abs(i - j);
          }
          if (total == A[i]) {
            out[i] = ch;
            taken[k] = true;
            dfs(s, out, ch);
            out[i] = ' ';
            taken[k] = false;
          }
        }
      }
    };

    string out(m, ' ');
    dfs(s, out, ' ');

    cout << ans << endl;
  }
}
