#include <iostream>
#include "catch.hpp"

using namespace std;

struct Node {
  int element;
  Node* left;
  Node* right;
  Node(int _element) {
    element = _element;
    left = nullptr;
    right = nullptr;
  }
};

class BinarySearchTree {
public:
  BinarySearchTree() {
    root = nullptr;
  }
  void insert(int v);
  void print();
  void remove(int v);
  Node* find(int v);
  Node* findMin();

private:
  Node *root;

  void insert(int, Node *&);
  void print(Node *, int);
  void remove(int, Node *&);
  Node* find(int, Node *);
  Node* findMin(Node *);
};

// insert
void BinarySearchTree::insert(int v) {
  insert(v, root);
}

void BinarySearchTree::insert(int v, Node *&t) {
  if (t == nullptr) {
    t = new Node(v);
  } else if (t->element > v) {
    insert(v, t->left);
  } else if (t->element < v) {
    insert(v, t->right);
  }
}

// find
Node* BinarySearchTree::find(int v) {
  return find(v, root);
}

Node* BinarySearchTree::find(int v, Node *t) {
  if (t == nullptr) return t;
  if (t->element == v) return t;
  if (v < t->element) {
    return find(v, t->left);
  } else {
    return find(v, t->right);
  }
}

// findMin
Node* BinarySearchTree::findMin() {
  return findMin(root);
}

Node* BinarySearchTree::findMin(Node *t) {
  while (t != nullptr && t->left != nullptr) {
    t = t->left;
  }
  return t;
}

// remove
void BinarySearchTree::remove(int x) {
  remove(x, root);
}

void BinarySearchTree::remove(int x, Node *&t) {
  if (t == nullptr) {
    // nothing to do
    return;
  }
  if (x < t->element) {
    remove(x, t->left);
  } else if (x > t->element) {
    remove(x, t->right);
  } else {
    // node found!
    if (t->left != nullptr && t->right != nullptr) {
      // two children
      // copy data from lowest child
      t->element = findMin(t->right)->element;
      remove(t->element, t->right);
    } else {
      // one children
      Node *old = t;
      t = (t->left == nullptr) ? t->right : t->left;
      delete old;
    }
  }
}

// print

void BinarySearchTree::print() {
  print(root, 0);
}

void BinarySearchTree::print(Node *t, int level) {
  if (t == nullptr) {
    return;
  }
  string spaces(level * 2, ' ');
  cout << spaces << t->element << "\n";
  print(t->right, level + 1);
  print(t->left, level + 1);
}

void setup(BinarySearchTree &t) {
  t.insert(4);
  t.insert(5);
  t.insert(2);
  t.insert(1);
  t.insert(3);
}

TEST_CASE("Binary Search Tree") {
  BinarySearchTree t;

  SECTION("has an insert method") {
    setup(t);
  }

  SECTION("has a node with id 3") {
    setup(t);
    Node *n = t.find(3);
    REQUIRE(n != nullptr);
    REQUIRE(n->element == 3);
  }

  SECTION("finds the min node") {
    setup(t);
    Node *n = t.findMin();
    REQUIRE(n != nullptr);
    REQUIRE(n->element == 1);
  }

  SECTION("finds the min node") {
    setup(t);
    Node *n = t.findMin();
    REQUIRE(n != nullptr);
    REQUIRE(n->element == 1);
  }
}
