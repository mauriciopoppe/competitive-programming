#include <vector>
#include <bits/stdc++.h>
#include <iterator>     // std::next

#include "test_framework/generic_test.h"
using namespace std;

struct VectorIt {
    bool operator()(const VectorIt &p1, const VectorIt &p2) const {
        return *(p1.cur) > *(p2.cur);
    }

    vector<int>::const_iterator cur, end;
};

vector<int> MergeSortedArrays(const vector<vector<int>>& sorted_arrays) {
    priority_queue<VectorIt, vector<VectorIt>, VectorIt> pq;
    for (const auto& it: sorted_arrays) {
        if (!it.empty()) {
            pq.emplace(VectorIt{it.begin(), it.end()});
        }
    }

    vector<int> out;
    while (!pq.empty()) {
        VectorIt it = pq.top();
        pq.pop();
        out.emplace_back(*(it.cur));
        if (next(it.cur) != it.end) {
            pq.emplace(VectorIt{next(it.cur), it.end});
        }
    }
    return out;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"sorted_arrays"};
  return GenericTestMain(args, "sorted_arrays_merge.cc",
                         "sorted_arrays_merge.tsv", &MergeSortedArrays,
                         DefaultComparator{}, param_names);
}
