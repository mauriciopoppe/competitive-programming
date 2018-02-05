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
		left = right = NULL;
		value = _value;
	}
};

struct Tree {
	Node *root;

	Tree() {
		root = NULL;
	}

	void insert(int value) {
		root = insert(root, new Node(value));
	}

	Node *insert(Node *current, Node *newNode) {
		if (!current) {
			return newNode;
		}

		if (current->value > newNode->value) {
			current->left = insert(current->left, newNode);
		} else {
			current->right = insert(current->right, newNode);
		}
		return current;
	}
};

void solve(Node *root) {
	typedef pair<Node*, int> pni ;
	queue<pni> q;
	q.push(pni(root, 0));
	int top_level = 0;
	while (!q.empty()) {
		Node *current = q.front().first;
		int level = q.front().second;
		if (level != top_level) {
			cout << endl;
			top_level = level;
		}

		cout << current->value << " ";
		q.pop();
		if (current->left) {
			q.push(pni(current->left, level + 1));
		}
		if (current->right) {
			q.push(pni(current->right, level + 1));
		}
	}
}

int main() {
	Tree t;
	t.insert(7);
	t.insert(5);
	t.insert(4);
	t.insert(6);
	t.insert(8);
	t.insert(9);
	t.insert(10);
	t.insert(1);
	solve(t.root);
	return 0;
}