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
			// insert to the left since this node has a greater value
			root->left = add(root->left, value);
		} else {
			// insert to the right since this node has a less than or equal value
			root->right = add(root->right, value);
		}

		return root;
	}
};

Node *find_next(Node *root, int k) {
	Node *best = NULL;
	if (!root) {
		return best;
	}
	if (root->value > k) {
		best = root;
		Node *better = find_next(root->left, k);
		if (better) {
			best = better;
		}
	} else {
		best = find_next(root->right, k);
	}

	return best;
}

int main() {
	BST t;
	t.add(19);
	t.add(7);
	t.add(3);
	t.add(11);
	t.add(2);
	t.add(5);
	t.add(11);
	t.add(17);
	t.add(13);
	t.add(43);
	t.add(23);
	t.add(47);
	t.add(53);
	t.add(37);
	t.add(29);
	t.add(41);
	t.add(31);

	Node *dest = find_next(t.root, 19);
	if (dest) cout << dest->value << endl;
	return 0;
}