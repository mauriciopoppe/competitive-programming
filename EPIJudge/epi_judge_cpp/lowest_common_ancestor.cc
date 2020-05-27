#include <memory>

#include "binary_tree_node.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"
using std::unique_ptr;

struct State {
    int matches = 0;
    BinaryTreeNode<int> *node;
};

State LCA(const unique_ptr<BinaryTreeNode<int>>& tree,
          const unique_ptr<BinaryTreeNode<int>>& node0,
          const unique_ptr<BinaryTreeNode<int>>& node1) {
    State next = {0, nullptr};
    if (tree == nullptr) {
        return next;
    }
    State left = LCA(tree->left, node0, node1);
    if (left.matches == 2) return left;
    State right = LCA(tree->right, node0, node1);
    if (right.matches == 2) return right;
    next.matches = left.matches + right.matches + (tree == node0) + (tree == node1);
    if (next.matches == 2) next.node = tree.get();
    return next;
}

BinaryTreeNode<int>* Lca(const unique_ptr<BinaryTreeNode<int>>& tree,
                         const unique_ptr<BinaryTreeNode<int>>& node0,
                         const unique_ptr<BinaryTreeNode<int>>& node1) {
    return LCA(tree, node0, node1).node;
}
int LcaWrapper(TimedExecutor& executor,
               const unique_ptr<BinaryTreeNode<int>>& tree, int key0,
               int key1) {
  const unique_ptr<BinaryTreeNode<int>>& node0 = MustFindNode(tree, key0);
  const unique_ptr<BinaryTreeNode<int>>& node1 = MustFindNode(tree, key1);

  auto result = executor.Run([&] { return Lca(tree, node0, node1); });

  if (!result) {
    throw TestFailure("Result can not be nullptr");
  }
  return result->data;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "tree", "key0", "key1"};
  return GenericTestMain(args, "lowest_common_ancestor.cc",
                         "lowest_common_ancestor.tsv", &LcaWrapper,
                         DefaultComparator{}, param_names);
}
