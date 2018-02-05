#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int BUFFER = 10;
vector<ll> numbers;
ll dp[200 + BUFFER][10 + BUFFER][20 + BUFFER];
int d, m;

ll mod(ll n) {
  return (n % d + d) % d;
}

ll rec(int i, int taken, int sum) {
  if (taken == m) {
    // printf("%d taken %d - sum %d\n", i, taken, sum);
    if (sum == 0) {
      // printf("cnt++\n");
      return 1;
    }
    return 0;
  }
  if (i == numbers.size()) { return 0; }
  ll &ans = dp[i][taken][sum];
  if (ans != -1) return ans;
  ll with = rec(i + 1, taken + 1, (int)mod((ll)sum + numbers[i]));
  // printf("taken %d, %d + %d = %d\n", taken + 1, sum, numbers[i], mod(sum + numbers[i]));
  ll without = rec(i + 1, taken, sum);
  return ans = with + without;
}

int main() {
  int N, Q;
  int cas = 1;
  while (cin >> N >> Q) {
    if (N == Q && Q == 0) break;
    numbers.resize(N);
    rep(i, 0, N) cin >> numbers[i];
    printf("SET %d:\n", cas++);
    rep(q, 0, Q) {
      cin >> d >> m;
      memset(dp, -1, sizeof dp);
      printf("QUERY %d: %lld\n", q + 1, rec(0, 0, 0));
    }
  }
}
