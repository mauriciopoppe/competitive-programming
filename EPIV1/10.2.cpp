#include "./base.h"

struct Node {
	int value;
	Node *left, *right;
	Node(int _value) {
		value = _value;
		left = NULL;
		right = NULL;
	}
};

class BST {
public:
	Node *root;

	BST() {
		root = NULL;
	}

	void add(int value) {
		root = add(root, value);
	}

	Node *add(Node *root, int value) {
		if (!root) {
			return new Node(value);
		}
		if (root->value > value) {
			root->left = add(root->left, value);
		} else {
			root->right = add(root->right, value);
		}
		return root;
	}

	Node *find(int value) {
		return find(root, value);
	}

	Node *find(Node *node, int value) {
		if (!node) {
			return NULL;
		}
		if (node->value == value) {
			return node;
		}
		if (node->value > value) {
			return find(node->left, value);
		} else {
			return find(node->right, value);
		}
	}

	void inorder() {
		inorder(root, 0);
	}

	void preorder() {
		preorder(root, 0);
	}

	void inorder(Node *root, int level) {
		if (!root) {
			return;
		}
		inorder(root->left, level+1);
		printf("%s%2d\n", string(level*2, ' ').c_str(), root->value);
		inorder(root->right, level+1);
	}

	void preorder(Node *root, int level) {
		if (!root) {
			return;
		}
		printf("%s%2d\n", string(level*2, ' ').c_str(), root->value);
		preorder(root->left, level+1);
		preorder(root->right, level+1);
	}

	void *lca(int a, int b) {
		Node *common = lca(root, find(a), find(b));
		printf("lca(%d, %d) = %d\n", a, b, common->value);
	}

	Node *lca(Node *current, Node *a, Node *b) {
		if (!current) {
			return NULL;
		}
		Node *left = lca(current->left, a, b);
		Node *right = lca(current->right, a, b);
		// a and b are on different branches
		if (right && left) {
			return current;
		}

		bool equal = (current == a || current == b);
		// either:
		// - a is this node and b is a descendant
		// - b is this node and a is a descendant
		if (equal && (right || left)) {
			return current;
		}

		// both a and b are current!
		if (equal && !(right && left)) {
			return current;
		}

		// both nodes are descendants on the left or right branches
		if (right) {
			return right;
		}
		if (left) {
			return left;
		}

		// unreachable?
		return NULL;
	}

};

int main() {
	BST tree;
	tree.add(10);
	tree.add(5);
	tree.add(1);
	tree.add(7);
	tree.add(6);
	tree.add(15);
	tree.add(14);
	tree.add(18);
	tree.add(17);
	tree.add(19);
	tree.preorder();
	tree.lca(10, 10);
	tree.lca(17, 6);
	tree.lca(6, 7);
	tree.lca(14, 17);
	tree.lca(14, 14);
	return 0;
}
