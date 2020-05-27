#include <bits/stdc++.h>
#define INF int(1e9*2)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

void solve(int n) {
  int size = (int)sqrt(n);

  int p = 1;
  vector<int> m = {1, size, -1, -size};
  for (int it = size - 1; it >= 2; it -= 2) {
    for (int i = 0; i < 4; i += 1) {
      int n_it = it;
      do {
        if (--n >= 0) {
          printf(" %d", p);
        }
        p += m[i];
      } while(--n_it);
    }
    p += size + 1;
  }
  printf(" %d", size * size / 2 + size / 2);
  printf("\n");
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve(1);
  solve(4);
  solve(9);
  solve(16);
  solve(25);
}
