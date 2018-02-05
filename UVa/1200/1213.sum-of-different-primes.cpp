#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void pre(vector<map<int, int>> &dp) {
  // state: n, parent_count<int, int>
  dp[0][0] = 1;

  vector<int> primes = {2, 3};
  for (int i = 5; i <= 1120; i += 2) {
    int j;
    for (j = 0; j < primes.size(); j += 1) {
      if ((i % primes[j]) == 0) break;
    }
    if (j == primes.size()) primes.push_back(i);
  }

  for (int p = 0; p < primes.size(); p += 1) {
    for (int i = 1121; i >= 0; i -= 1) {
      if (i - primes[p] < 0) break;
      for (auto it: dp[i - primes[p]]) {
        int ntaken = it.first;
        int ncount = it.second;
        if (ntaken + 1 <= 14) {
          dp[i][ntaken + 1] += ncount;
        }
      }
    }
  }
}

int main() {
  vector<map<int, int>> dp(1125);
  pre(dp);
  int n, k;
  while (cin >> n >> k) {
    if (n == k && k == 0) break;
    printf("%d\n", dp[n][k]);
  }
}
