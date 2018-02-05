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

Node *build_tree(vector<int> &v, int start, int end) {
	if (start == end) {
		return NULL;
	}
	int mid = start + (end - start) / 2;
	Node *root = new Node(v[mid]);
	root->left = build_tree(v, start, mid);
	root->right = build_tree(v, mid + 1, end);
	return root;
}

void traverse(Node *node) {
	if (node) {
		traverse(node->left);
		cout << node->value << endl;
		traverse(node->right);
	}
}

int main() {
	int a[] = {1, 2, 3, 4, 7, 9, 15, 20, 25, 100};
	vector<int> v(a, a + 10);
	Node *root = build_tree(v, 0, v.size());
	traverse(root);

	return 0;
}