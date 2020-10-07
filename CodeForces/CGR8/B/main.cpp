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

  unsigned long long n;
  while (cin >> n) {

    vector<unsigned long long> p(10, 1);
    int k = 0;
    unsigned long long prod = 1;
    while (prod < n) {
      prod = prod / p[k] * (p[k] + 1);
      p[k]++;
      k = (k + 1) % 10;
    }
    string str = "codeforces";
    string out;
    for (int i = 0; i < str.size(); i += 1) {
      out += string(p[i], str[i]);
    }
    cout << out << endl;
  }
  return 0;
}

