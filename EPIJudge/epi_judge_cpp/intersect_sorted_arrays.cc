#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

vector<int> IntersectTwoSortedArrays(const vector<int>& A,
                                     const vector<int>& B) {
  int ia = 0;
  int ib = 0;
  vector<int> output;
  while (ia < A.size() && ib < B.size()) {
    if (A[ia] == B[ib]) {
      if (output.size() == 0 || output.back() != A[ia]) {
        output.push_back(A[ia]);
      }
      ia++;
      ib++;
    } else if (A[ia] < B[ib]) {
      ia++;
    } else {
      ib++;
    }
  }

  return output;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "B"};
  return GenericTestMain(
      args, "intersect_sorted_arrays.cc", "intersect_sorted_arrays.tsv",
      &IntersectTwoSortedArrays, DefaultComparator{}, param_names);
}
