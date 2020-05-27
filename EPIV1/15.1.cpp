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
	Node (int _value) {
		value = _value;
		left = right = NULL;
	}
};

bool is_bst(Node *node, int low, int up) {
	if (!node) {
		return true;
	}
	if (node->value < low || node->value > up) {
		return false;
	}
	return is_bst(node->left, low, node->value) && 
		is_bst(node->right, node->value, up);
}

bool is_bst(Node *root) {
	return is_bst(root, numeric_limits<int>::min(), numeric_limits<int>::max());
}

int main() {
	Node *root = new Node(10);
	root->left = new Node(5);
	root->left->left = new Node(3);
	root->left->right = new Node(9);
	root->right = new Node(15);
	root->right->left = new Node(14);
	root->right->right = new Node(16);
	cout << is_bst(root) << endl;
	return 0;
}