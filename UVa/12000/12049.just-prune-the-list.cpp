
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

  int t;
  int n, m, k;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    map<int, int> m1, m2;
    for (int i = 0; i < n; i += 1) {
      cin >> k;
      m1[k]++;
    }
    for (int i = 0; i < m; i += 1) {
      cin >> k;
      m2[k]++;
    }

    int total = 0;
    for (auto it = m1.begin(); it != m1.end(); it++) {
      total += abs(m1[it->first] - m2[it->first]);
    }
    for (auto it = m2.begin(); it != m2.end(); it++) {
      if (m1.count(it->first) == 0) {
        total += m2[it->first];
      }
    }
    cout << total << endl;
  }

  return 0;
}
