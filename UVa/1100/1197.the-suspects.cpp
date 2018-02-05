#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct UnionFind {
  vi rank, p;

  UnionFind(int n) {
    rank.assign(n, 0);
    p.assign(n, 0);
    rep(i, 0, n) p[i] = i;
  }

  int find_set(int i) { return p[i] == i ? i : p[i] = find_set(p[i]); }
  bool same_set(int i, int j) { return find_set(i) == find_set(j); }
  void union_set(int i, int j) {
    if (!same_set(i, j)) {
      i = find_set(i);
      j = find_set(j);
      if (rank[i] > rank[j]) p[j] = i;
      else {
        p[i] = j;
        if (rank[i] == rank[j]) rank[j]++;
      }
    }
  }
};

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  int n, m;
  while (cin >> n >> m) {
    if (!n && !m) break;
    UnionFind uf(n);
    rep(i, 0, m) {
      int k;
      cin >> k;
      vi group(k);
      rep(j, 0, k) cin >> group[j];
      rep(j, 1, k) {
        uf.union_set(group[j - 1], group[j]);
      }
    }

    int total = 1;
    rep(i, 1, n) {
      total += uf.same_set(0, i);
    }
    cout << total << "\n";
  }
}
