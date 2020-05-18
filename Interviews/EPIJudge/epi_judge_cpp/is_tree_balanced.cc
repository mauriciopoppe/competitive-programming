#include <cmath>
#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
using namespace std;

int height(const unique_ptr<BinaryTreeNode<int>> &node, bool &valid) {
    if (!node) return 0;
    if (!valid) return -1;
    int height_left = height(node->left, valid);
    int height_right = height(node->right, valid);
    if (abs(height_left - height_right) > 1) {
        valid = false;
    }
    return max(height_left, height_right) + 1;
}

bool IsBalanced(const unique_ptr<BinaryTreeNode<int>>& tree) {
  bool isValid = true;
  height(tree, isValid);
  return isValid;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_balanced.cc", "is_tree_balanced.tsv",
                         &IsBalanced, DefaultComparator{}, param_names);
}
