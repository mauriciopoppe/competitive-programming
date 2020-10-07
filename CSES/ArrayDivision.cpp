#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool ok(vector<long long> &num, int k, long long mid) {
  long long sum_partition = 0;
  int total_partition = 0;

  int i = 0;
  while (i < num.size()) {
    sum_partition = 0;
    while (i < num.size() && sum_partition + num[i] <= mid) {
      sum_partition += num[i];
      i++;
    }
    if (sum_partition > 0) ++total_partition;
    if (num[i] > mid) return false;
  }
  return k >= total_partition;
}

int main() {
  // cin.sync_with_stdio(0); cin.tie(0);
  // cin.exceptions(cin.failbit);

  int n, k;
  cin >> n >> k;

  vector<long long> num(n);
  long long total = 0;
  for (auto &x: num) {
    cin >> x;
    total += x;
  }

  // int = 4 bytes
  // 00000000 00000000 00000100 00000000
  //
  // 00001000  8
  // 00001111  15
  // 2^

  long long lo = 0, hi = total;
  long long ans = hi;
  while (lo <= hi) {
    long long mid = lo + (hi - lo) / 2;
    if (ok(num, k, mid)) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  cout << ans << endl;
}
