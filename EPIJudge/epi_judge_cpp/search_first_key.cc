#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

int binsearch_using_stl(const vector<int> &A, int k) {
  auto it = lower_bound(A.begin(), A.end(), k);
  if (it == A.end()) {
    return -1;
  }
  if (*it != k) {
    return -1;
  }
  return it - A.begin();
}

int binsearch_manual(const vector<int> &A, int k) {
  if (A.size() == 0) return -1;

  // invariant
  //          A[i] >= k
  // [0 0 0 0 0 1 1 1 1]
  int lo = -1, hi = A.size()-1;
  while (hi - lo > 1) {
    int mid = lo + (hi - lo) / 2;
    if (A[mid] >= k) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  if (A[hi] != k) return -1;
  return hi;
}

int SearchFirstOfK(const vector<int>& A, int k) {
  return binsearch_manual(A, k);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "k"};
  return GenericTestMain(args, "search_first_key.cc", "search_first_key.tsv",
                         &SearchFirstOfK, DefaultComparator{}, param_names);
}
