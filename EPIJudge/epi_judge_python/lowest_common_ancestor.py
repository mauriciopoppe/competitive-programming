import functools
import collections
from typing import Optional

from binary_tree_node import BinaryTreeNode
from test_framework import generic_test
from test_framework.binary_tree_utils import must_find_node, strip_parent_link
from test_framework.test_failure import TestFailure
from test_framework.test_utils import enable_executor_hook


def lca(tree: BinaryTreeNode, node0: BinaryTreeNode,
        node1: BinaryTreeNode) -> Optional[BinaryTreeNode]:

    State = collections.namedtuple('State', ('n', 'node'))

    def traverse(tree, node0, node1):
        if not tree:
            return State(0, None)

        left = traverse(tree.left, node0, node1)
        if left.n == 2:
            return left

        right = traverse(tree.right, node0, node1)
        if right.n == 2:
            return right

        total = left.n + right.n + int(tree == node0) + int(tree == node1)
        node = None
        if total == 2:
            node = tree
        return State(total, node)

    # TODO - you fill in here.
    return traverse(tree, node0, node1).node


@enable_executor_hook
def lca_wrapper(executor, tree, key1, key2):
    strip_parent_link(tree)
    result = executor.run(
        functools.partial(lca, tree, must_find_node(tree, key1),
                          must_find_node(tree, key2)))

    if result is None:
        raise TestFailure('Result can\'t be None')
    return result.data


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('lowest_common_ancestor.py',
                                       'lowest_common_ancestor.tsv',
                                       lca_wrapper))
