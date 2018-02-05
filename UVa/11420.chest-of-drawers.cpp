#include <bits/stdc++.h>
#define INF int(1e9*2)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n;
int s;

const int MAX = 70;
ll dp[MAX][MAX];

ll solve(int locked, int rem) {
  if (locked < s) return 0;
  if (rem <= 0) return locked == s;

  ll &total = dp[locked][rem];
  if (total != -1) return total;

  total = locked == s;
  for (int i = rem; i >= 1; i--) {
    if (i == rem) {
      total += solve(locked - 1, rem - 1);
    } else {
      total += solve(locked - 2, i - 1);
    }
    // total += solve(locked, rem - 2);
  }

  return total;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n >> s) {
    if (n < 0 && s < 0) {
      break;
    }
    memset(dp, -1, sizeof dp);
    printf("%lld\n", solve(n, n));
  }
}
