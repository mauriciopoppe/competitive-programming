#include <bits/stdc++.h>
#define INF int(1e9*2)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
  int cas;
  cin >> cas;
  while (cas--) {
    int n;
    cin >> n;

    vector<int> v(n);
    map<int, int> last;
    set<int> pack;
    for (int i = 0; i < n; i++) cin >> v[i];

    int mx = -1;
    int last_deleted = 0;
    for (int i = 0; i < n; i++) {
      if (pack.find(v[i]) == pack.end()) {
        pack.insert(v[i]);
      } else {
        while (last_deleted <= last[v[i]]) {
          pack.erase(v[last_deleted++]);
        }
        pack.insert(v[i]);
      }
      last[v[i]] = i;
      mx = max(mx, (int)pack.size());
    }
    cout << mx << "\n";
  }
}
