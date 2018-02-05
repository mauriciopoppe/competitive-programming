#include <bits/stdc++.h>
#define INF int(1e9*2)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n;
ll MOD;
vector<ll> v;

const int MAX = 1001;
ll dp[MAX][MAX];

ll solve(int start, int take) {
  // assert(start <= n);
  // assert(take <= n);
  printf("(%d, %d)\n", start, take);
  if (start > n) return 0;
  if (take == 0) return 1;

  ll &total = dp[start][take];
  if (total != -1) return total;

  total = (v[start] * solve(start + 1, take - 1)) % MOD + solve(start + 1, take);
  total %= MOD;
  // for (int i = start; i < n - take + 1; i += 1) {
  //   ll prod = (v[i] * solve(i + 1, take - 1)) % MOD;
  //   total = (total + prod) % MOD;
    // while (i + 1 < n && v[i + 1] == v[i]) ++i;
  // }

  return total;
}

ll solve() {
  ll best = 0;
  for (int i = 1; i <= n; i += 1) {
    best = max(best, solve(0, i));
  }
  return best;
}

// ll solve() {
//   for (int i = 0; i <= n; i += 1) dp[0][i] = 1;

//   for (int i = 1; i <= n; i += 1) {
//     dp[i][i - 1] = 0;
//     for (int j = i; j <= n; j += 1) {
//       dp[i][j] = (dp[i - 1][j - 1] * v[j - 1]) % MOD + dp[i][j - 1];
//       dp[i][j] %= MOD;
//     }
//   }

//   ll best = 0;
//   for (int i = 1; i <= n; i += 1) {
//     best = max(best, dp[i][n]);
//   }
//   return best;
// }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n >> MOD) {
    if (n == 0 && MOD == 0) break;
    v.clear();
    v.resize(n);
    for (int i = 0; i <= n; i += 1) {
      for (int j = 0; j <= n; j += 1) {
        dp[i][j] = -1;
      }
    }
    for (int i = 0; i < n; i += 1) {
      cin >> v[i];
    }
    // sort(v.begin(), v.end());

    printf("%lld\n", solve());
  }
}
