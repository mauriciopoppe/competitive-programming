#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define MS(a, v) memset(a, v, sizeof a)
#define NL printf("\n")
#define INF 1e9
#define PI acos(-1)
#define EPS 1e-9
#define TR(ar, it) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )

typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

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
		inorder(root);
	}
	
	void inorder(Node *root) {
		if (!root) {
			return;
		}
		
		inorder(root->left);
		printf("%d\n", root->value);
		inorder(root->right);				
	}

	void *lca(int a, int b) {
		Node *common = lca(root, find(a), find(b));
		cout << "lca=" << common->value << endl;
	}

	Node *lca(Node *current, Node *a, Node *b) {
		if (!current) {
			return NULL;
		}
		Node *left = lca(current->left, a, b);
		Node *right = lca(current->right, a, b);
		bool equal = (current == a || current == b);
		// a and b are on different branches
		if (right && left) {
			return current;
		}
		if ((right || left) && equal) {
			return current;
		}

		if (right) {
			return right;
		}
		if (left) {
			return left;
		}
		return equal ? current : NULL;
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
	tree.inorder();
	tree.lca(10, 10);
	tree.lca(17, 6);
	tree.lca(6, 7);
	tree.lca(14, 17);
	return 0;
}