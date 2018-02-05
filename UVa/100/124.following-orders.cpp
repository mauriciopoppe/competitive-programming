#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(vi &vert, vector<vi> &edges, vi &indeg, string s) {
  int nperm = 0;
  rep(i, 0, 26) {
    if (vert[i] && indeg[i] == 0) {
      // remove i from graph
      trav(e, edges[i]) {
        indeg[e]--;
      }
      vert[i] = 0;

      solve(vert, edges, indeg, s + (char)(i + 'a'));
      nperm = 1;

      // restore i in the graph
      trav(e, edges[i]) {
        indeg[e]++;
      }
      vert[i] = 1;
    }
  }
  if (!nperm) cout << s << "\n";
}

int main() {
  // cin.sync_with_stdio(0); cin.tie(0);
  int cas = 0;
  string line;
  while (getline(cin, line)) {
    string sol = "";
    if (cas++) printf("\n");

    vi vert(26, 0);
    for (int i = 0; i < line.size(); i += 2) {
      vert[line[i] - 'a'] = 1;
    }
    getline(cin, line);

    vi indeg(vert.size(), 0);
    vector<vi> edges(vert.size());
    for (int i = 0; i < line.size(); i += 4) {
      int a = line[i] - 'a';
      int b = line[i + 2] - 'a';
      edges[a].push_back(b);
      indeg[b]++;
    }

    solve(vert, edges, indeg, sol);
  }
}
