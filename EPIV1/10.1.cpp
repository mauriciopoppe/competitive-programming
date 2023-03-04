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

int is_balanced(Node *current, bool &balanced) {
	if (!balanced) {
		return -1;
	}
	if (!current) {
		return 0;
	}

	int left_height = is_balanced(current->left, balanced);
	int right_height = is_balanced(current->right, balanced);
	int height = max(left_height, right_height);
	if (abs(left_height - right_height) > 1) {
		balanced = false;
	}
	return height + 1;
}

void is_balanced(Node *n) {
	bool balanced = true;
	is_balanced(n, balanced);
	cout << balanced << endl;
}

int main() {
	return 0;
}
