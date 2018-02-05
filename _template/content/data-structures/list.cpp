#include <iostream>
#include <algorithm>
#include <cassert>

struct Node {
  int value;
  Node *next;
  explicit Node(const int x) {
    value = x;
    next = nullptr;
  }
};

class List {
  private:
    Node *head;

  public:
    List() {
      head = nullptr;
    }

    void push(int x) {
      if (!head) {
        head = new Node(x);
        return;
      }
      Node *newNode = new Node(x);
      Node *it = head;
      while (it->next) {
        it = it->next;
      }
      it->next = newNode;
    }

    void print() {
      Node *it = head;
      int i = 0;
      while (it) {
        if (i++) std::cout << " -> ";
        std::cout << it->value;
        it = it->next;
      }
      std::cout << "\n";
    }
};

int main() {
  List l;
  l.push(1);
  l.push(2);
  l.push(3);
  l.print();
}
