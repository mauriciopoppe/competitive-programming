#include <memory>
#include <vector>

#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;
using std::vector;

vector<vector<int>> BinaryTreeDepthOrder(
    const unique_ptr<BinaryTreeNode<int>>& tree) {
  vector<vector<int>> out;
  if (!tree.get()) { return out; }

  queue<pair<int, BinaryTreeNode<int>*>> q;
  q.push({ 0, tree.get() });
  while (!q.empty()) {
    int level;
    BinaryTreeNode<int>* node;
    tie(level, node) = q.front();
    q.pop();
    if (level + 1 > out.size()) {
      out.push_back(vector<int>());
    }
    out[level].push_back(node->data);
    if (node->left != nullptr) {
      q.push({ level+1, node->left.get() });
    }
    if (node->right != nullptr) {
      q.push({ level+1, node->right.get() });
    }
  }
  return out;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "tree_level_order.cc", "tree_level_order.tsv",
                         &BinaryTreeDepthOrder, DefaultComparator{},
                         param_names);
}
