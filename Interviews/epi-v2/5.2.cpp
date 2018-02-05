#include <bits/stdc++.h>
#define INF int(1e9*2)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

/*
 * increment an arbitrary precision integer represented as a vector A to A+1
 */
void increment(vector<int> &A) {
  A[A.size() - 1]++;
  for (int i = A.size() - 1; i > 0 && A[i] == 10; i -= 1) {
    A[i] = 0;
    A[i - 1]++;
  }
  if (A[0] == 10) {
    A[0] = 1;
    A.push_back(0);
  }
}

int main() {
  vector<int> A = {9,9,9};
  increment(A);
  for (auto a: A) {
    cout << a;
  }
  cout << endl;
}
