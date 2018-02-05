#include <bits/stdc++.h>
#define INF int(1e9*2)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

vector<pair<int, double>> items;

double dp[101];

double solve(int n) {
  if (n <= 0) return 0;

  double &cost = dp[n];
  if (cost != -1) return cost;

  cost = INF;
  for (int i = 0; i < items.size(); i += 1) {
    auto item = items[i];
    cost = min(cost, solve(n - item.first) + item.second);
  }
  return cost;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  double single;
  int n_items;
  int cas = 1;
  while (cin >> single >> n_items) {
    items.clear();
    fill(dp, dp + 101, -1);
    // memset(dp, -1, sizeof dp);

    items.push_back({ 1, single });

    int pack;
    double cost;
    for (int i = 0; i < n_items; i += 1) {
      cin >> pack >> cost;
      items.push_back({ pack, cost });
    }

    string buf;
    getline(cin, buf);


    printf("Case %d:\n", cas++);

    string line;
    getline(cin, line);
    istringstream ss(line);
    int number;
    while (ss >> number) {
      printf("Buy %d for $%.2f\n", number, solve(number));
    }
  }
}
