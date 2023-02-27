#include <cmath>
#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
using namespace std;

int IsBalancedWithValid(const unique_ptr<BinaryTreeNode<int>> &node, bool &valid) {
  if (!node) return 0;
  if (!valid) return 0;
  int hleft = IsBalancedWithValid(node->left, valid);
  int hright = IsBalancedWithValid(node->right, valid);
  if (abs(hleft - hright) > 1) {
    valid = false;
  }
  return max(hleft, hright) + 1;
}

bool IsBalanced(const unique_ptr<BinaryTreeNode<int>>& tree) {
  bool valid = true;
  IsBalancedWithValid(tree, valid);
  return valid;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_balanced.cc", "is_tree_balanced.tsv",
                         &IsBalanced, DefaultComparator{}, param_names);
}
