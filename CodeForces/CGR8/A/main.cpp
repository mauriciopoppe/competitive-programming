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

  int t, a, b, n;
  cin >> t;
  while (t--) {
    int A, B;
    cin >> A >> B >> n;
    int total = 0;
    int a, b;
    a = A;
    b = B;
    while (true) {
      a += b;
      ++total;
      if (a > n) break;
      swap(a, b);
    }

    a = B;
    b = A;
    int total2 = 0;
    while (true) {
      a += b;
      ++total2;
      if (a > n) break;
      swap(a, b);
    }
    cout << min(total, total2) <<endl;
  }
}
