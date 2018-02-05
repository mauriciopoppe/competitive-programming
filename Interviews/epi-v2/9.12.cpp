#include <bits/stdc++.h>
using namespace std;

struct Node {
  Node *left, *right;
  char value;
  Node(char _v) {
    left = right = nullptr;
    value = _v;
  }
};

Node* createTree(string inorder, string preorder) {
  if (!inorder.size()) return nullptr;
  Node *root = new Node(preorder[0]);
  auto i = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();

  string inorder_left = inorder.substr(0, i);
  string inorder_right = inorder.substr(i + 1);
  string preorder_left = preorder.substr(1, inorder_left.size() + 1);
  string preorder_right = preorder.substr(inorder_left.size() + 1);
  root->left = createTree(inorder_left, preorder_left);
  root->right = createTree(inorder_right, preorder_right);
  return root;
}

void printTree(Node *t, int level = 0, char type = '-') {
  if (t) {
    printf("%*c(%c)\n", level * 2, t->value, type);
    printTree(t->left, level + 1, 'L');
    printTree(t->right, level + 1, 'R');
  }
}

int main() {
  string inorder = "fbaehcdig";
  string preorder = "hbfeacdgi";
  Node *t = createTree(inorder, preorder);
  printTree(t);
  printTree(createTree("21", "12"));
}
