#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  int m, n;
  while (cin >> m >> n) {
    // store in reverse order
    vector<vector<pii>> mat(n, vector<pii>());

    for (int i = 0; i < m; i += 1) {
      int n_els;
      cin >> n_els;
      vector<pii> v(n_els);
      for (int j = 0; j < n_els; j++) cin >> v[j].first;
      for (int j = 0; j < n_els; j++) cin >> v[j].second;

      for (int j = 0; j < n_els; j++) {
        int row = v[j].first - 1;
        int value = v[j].second;
        pii entry = {i + 1, value};
        mat[row].push_back(entry);
      }
    }

    // output
    printf("%d %d\n", n, m);
    for (int i = 0; i < n; i += 1) {
      printf("%d", (int)mat[i].size());
      for (int j = 0; j < mat[i].size(); j++) {
        printf(" %d", mat[i][j].first);
      }
      printf("\n");
      for (int j = 0; j < mat[i].size(); j++) {
        if (j) printf(" ");
        printf("%d", mat[i][j].second);
      }
      printf("\n");
    }
  }
}
