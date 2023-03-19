#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
vector<int> MatrixInSpiralOrder(const vector<vector<int>>& square_matrix) {
  map<pair<int, int>, bool> seen;
  int n = square_matrix.size();
  vector<pair<int, int>> diff = {{0,1}, {1,0}, {0,-1}, {-1,0}};
  vector<int> out;

  function<int(int,int)> out_of_bounds = [&](int x, int y) {
    return x < 0 || x >= square_matrix.size() || y < 0 || y >= square_matrix[0].size() || seen[{x,y}];
  };

  int k = 0;
  int x = 0, y = 0;
  for (int i = 0; i < n*n; i += 1) {
    out.push_back(square_matrix[x][y]);
    seen[{x,y}] = true;
    int cx = x + diff[k].first;
    int cy = y + diff[k].second;
    if (out_of_bounds(cx, cy)) {
      k = (k + 1) % 4;
      cx = x + diff[k].first;
      cy = y + diff[k].second;
    }
    x = cx;
    y = cy;
  }

  return out;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"square_matrix"};
  return GenericTestMain(args, "spiral_ordering.cc", "spiral_ordering.tsv",
                         &MatrixInSpiralOrder, DefaultComparator{},
                         param_names);
}
