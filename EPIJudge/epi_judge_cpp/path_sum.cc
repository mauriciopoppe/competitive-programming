#include <memory>

#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;

bool HasPathSum(const unique_ptr<BinaryTreeNode<int>>& tree,
                int remaining_weight) {
  if (!tree) return false;
  if (tree && !tree->left && !tree->right) return remaining_weight == tree->data;
  int next_remaining_weight = remaining_weight - tree->data;
  return HasPathSum(tree->left, next_remaining_weight) || HasPathSum(tree->right, next_remaining_weight);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree", "remaining_weight"};
  return GenericTestMain(args, "path_sum.cc", "path_sum.tsv", &HasPathSum,
                         DefaultComparator{}, param_names);
}
