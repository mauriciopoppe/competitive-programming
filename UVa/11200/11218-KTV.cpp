#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a) for (int i = 0; i < (a); i++)
#define FORT(i,a,b) for (int i = a; i < (b); i++)
#define TRAV(a,x) for (auto& a: x)
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)(x).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  int cas = 1;
  while (cin >> n && n) {
    map<int, int> scores;
    vector<vector<int>> dp(100, vector<int>(1<<10, -1));

    for (int i = 0; i < n; i += 1) {
      int a, b, c, s;
      cin >> a >> b >> c>> s;
      a--;
      b--;
      c--;
      int k = (1 << a) | (1 << b) | (1 << c);
      bitset<9> bk(k);
      // cout << bk << endl;
      scores[k] = s;
    }

    dp[0][0] = 0;
    int t = 1;
    int best = -1;
    for (auto score: scores) {
      int k = score.first;
      int s = score.second;

      for (int i = 0; i < t; i += 1) {
        for (int j = 0; j < (1 << 9); j += 1) {
          if (dp[i][j] != -1 && (j & k) == 0) {
            dp[t][k|j] = max(dp[t][k|j], dp[i][j] + s);
            // printf("i=%d %d %d\n", i, j, k);
            if ((k|j) == (1 << 9) - 1) {
              bitset<9> bj(j), bk(k);
              // cout << bj << " " << bk << endl;
              best = max(best, dp[t][k|j]);
            }
          }
        }
      }
      ++t;
    }

    printf("Case %d: %d\n", cas++, best);
  }

  return 0;
}
