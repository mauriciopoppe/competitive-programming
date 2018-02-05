#include <bits/stdc++.h>
#define INF int(1e9*2)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

/**
 * Permutates an array according to a defined configuration
 */
void solve(vector<int> &perm, vector<int> &A) {
  for (int i = 0; i < A.size(); i += 1) {
    int from = i;
    int to = perm[from] - 1;
    if (A[from] > 0) {
      while (A[to] > 0) {
        swap(A[from], A[to]);
        A[to] *= -1;
        to = perm[to] - 1;
      }
    }
  }

  for (int i = 0; i < A.size(); i += 1) {
    A[i] *= -1;
  }
}

void print(vector<int> &A) {
  for (int i = 0; i < A.size(); i += 1) {
    printf(" %d", A[i]);
  }
  printf("\n");
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> A = {1, 2, 3, 4};
  vector<int> perm = {4, 3, 1, 2};
  solve(perm, A);
  print(A);

  A = {1, 2, 3, 4, 5, 6};
  perm = {2, 3, 1, 4, 6, 5};
  solve(perm, A);
  print(A);
}

