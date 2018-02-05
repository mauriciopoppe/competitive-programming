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
	Node *left, *right, *parent;
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
		root = add(root, NULL, value);
	}
	
	Node *add(Node *root, Node *parent, int value) {
		if (!root) {
			Node *newNode = new Node(value);
			newNode->parent = parent;
			return newNode;
		} 
		if (root->value > value) {
			root->left = add(root->left, root, value);
		} else {
			root->right = add(root->right, root, value);
		}
		return root;
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
};

void next_level_order(Node *root) {
	Node *curr = root;
	Node *best = NULL;	

	// has right children
	if (curr->right) {
		// find leftmost node starting on the right child
		best = curr->right;
		while (best->left) {
			best = best->left;
		}
 	} else {
 		// find parent whose left child is the current node
		while (curr->parent) {
			Node *parent = curr->parent;
			if (parent->left == curr) {
				best = parent;
				break;
			}
			curr = parent;
		}
 	}
 	if (best) {
 		cout << best->value << endl;
 	} else {
 		cout << "NO NEXT NODE" << endl;
 	}
}


int main() {
	BST t;
	t.add(10);
	t.add(5);
	t.add(1);
	t.add(7);
	t.add(6);
	t.add(15);
	t.add(14);
	t.add(18);
	t.add(17);
	t.add(19);

	// t.inorder();
	next_level_order(t.root->left->right->left);
	next_level_order(t.root->left->right);
	next_level_order(t.root);
	return 0;
}