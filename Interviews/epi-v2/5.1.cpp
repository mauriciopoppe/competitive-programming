#include <bits/stdc++.h>
using namespace std;

/*
 * dutch problem
 *
 * given an array A and an index i, rearrange the items so that
 * elements less than A[i] appear first then the elements equal to A[i]
 * and finally elements greater than A[i]
 */
void DutchFlagPartition(int pivot_index, vector<int> *A_ptr) {
  vector<int> &A = *A_ptr;
  int value = A[pivot_index];
  int i = 0;
  int j = 0;
  // move items less than value
  while (j < A.size()) {
    if (A[j] < value) {
      swap(A[i++], A[j++]);
    } else {
      j++;
    }
  }
  // move items greater than value
  i = j = A.size() - 1;
  while (j >= 0) {
    if (A[j] > value) {
      swap(A[i--], A[j--]);
    } else {
      j--;
    }
  }
}


int main() {
  vector<int> A = {5,4,2,3,2,4,1,1,2,5};
  DutchFlagPartition(2, &A);
  for (auto a: A) {
    cout << " " << a;
  }
  cout << "\n";

  return 0;
}

