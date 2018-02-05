#include <bits/stdc++.h>
#define INF int(1e9*2)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int dp[501][501];

int solve(int k, int n) {
  if (n == 0) return 0;
  if (n == 1) return k;

  int &res = dp[k][n];
  if (res != -1) return res;

  res = INF;
  for (int i = 1; i <= n; i += 1) {
    int weight = k + i - 1;
    int total = n * weight;
    if (i > 2) total += solve(k, i - 1);
    if (n - i >= 2) total += solve(weight + 1, (n - i));
    // printf("k=%d n=%d i=%d total=%d\n", k, n, i, total);
    res = min(res, total);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  int cas;
  cin >> cas;
  for (int z = 0; z < cas; z += 1) {
    cin >> n >> k;
    // printf("[");
    // for (int i = 1; i <= n; i += 1) {
    //   printf("%d ", i + k);
    // }
    // printf("]\n");
    memset(dp, -1, sizeof dp);
    printf("Case %d: %d\n", z + 1, solve(k + 1, n));
  }
}
