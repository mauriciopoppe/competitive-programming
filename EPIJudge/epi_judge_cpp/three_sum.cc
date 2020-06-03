#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

bool HasThreeSum(vector<int> A, int t) {
  sort(A.begin(), A.end());
  for (int i = 0; i < (int) A.size(); i += 1) {
      int target = t - A[i];
      int lo = i;
      int hi = (int) A.size() - 1;
      while (lo <= hi) {
          int cand = A[lo] + A[hi];
          if (cand == target) return true;
          if (cand > target) hi--;
          if (cand < target) lo++;
      }
  }
  return false;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "t"};
  return GenericTestMain(args, "three_sum.cc", "three_sum.tsv", &HasThreeSum,
                         DefaultComparator{}, param_names);
}
