#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, int> pii;
typedef vector<int> vi;

vector<pii> tops;
vector<pii> bottoms;
pii dp[1001][1001];
int maxT;
int maxB;

pii best(pii a, pii b) {
  if (a.first > b.first) return a;
  if (a.first == b.first && a.second < b.second) return a;
  return b;
}

pii operator+(pii a, pii b) {
  return { a.first + b.first, a.second + b.second };
}

pii solve(int t, int b) {
  if (t == maxT) return { 0, 0 };
  if (b == maxB) return { 0, 0 };

  auto &ref = dp[t][b];
  if (ref.first != -1) return ref;

  // skip top
  ref = best(ref, solve(t + 1, b));
  // skip bottom
  ref = best(ref, solve(t, b + 1));
  if (tops[t].first == bottoms[b].first) {
    // take both
    ref = best(ref, pii(tops[t].second + bottoms[b].second, 1) +
        solve(t + 1, b + 1));
  }

  return ref;
}

int main() {
  int cas;
  cin >> cas;
  while (cas--) {

    map<string, int> rev;
    int id = 0;
    string s, t;
    int cost;

    cin >> maxT;
    tops.resize(maxT);
    rep (i, 0, maxT) {
      cin >> s >> t >> cost;
      if (!rev.count(t)) rev[t] = id++;
      int m = rev[t];
      tops[i] = { m, cost };
    }

    cin >> maxB;
    bottoms.resize(maxB);
    rep (i, 0, maxB) {
      cin >> s >> t >> cost;
      if (!rev.count(t)) rev[t] = id++;
      int m = rev[t];
      bottoms[i] = { m, cost };
    }

    rep (i, 0, maxT + 1) {
      rep (j, 0, maxB + 1) {
        dp[i][j] = { -1, -1 };
      }
    }

    auto sol = solve(0, 0);
    printf("%lld %d\n", sol.first, sol.second);
  }
}
