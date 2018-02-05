#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "catch.hpp"

using namespace std;

class BinaryHeap {
public:
  BinaryHeap() {
    currentSize = 0;
    heap.resize(1);
  }

  void insert(const int x);
  int findMin();
  void deleteMin();
  int getSize();

private:
  int currentSize;
  vector<int> heap;
  void balance(int index);
};

int BinaryHeap::getSize() {
  return currentSize;
}

void BinaryHeap::insert(int x) {
  if (currentSize == (int)(heap.size() - 1)) {
    heap.resize(heap.size() * 2);
  }
  int hole = ++currentSize;
  // hole > 1 means that hole has a parent
  for (; hole > 1 && x < heap[hole / 2]; hole /= 2) {
    heap[hole] = heap[hole / 2];
  }
  heap[hole] = x;
}

int BinaryHeap::findMin() {
  return heap[1];
}

void BinaryHeap::deleteMin() {
  if (heap.size() == 0) {
    throw "failure";
  }

  heap[1] = heap[currentSize--];
  balance(1);
}

void BinaryHeap::balance(int hole) {
  int child;
  for (; hole * 2 <= currentSize; hole = child) {
    child = hole * 2;
    // check the right child only if it exists
    // if child == currentSize that means that there's no right child
    if (child + 1 <= currentSize && heap[child + 1] < heap[child]) {
      // balance with right child
      child++;
    }
    if (heap[child] < heap[hole]) {
      swap(heap[hole], heap[child]);
    } else {
      break;
    }
  }
}

TEST_CASE("Binary Heap") {
  BinaryHeap bh;

  SECTION("inserts a node") {
    bh.insert(5);
    bh.insert(3);
    bh.insert(2);
    bh.insert(4);
    bh.insert(1);

    SECTION("gets the min value node") {
      REQUIRE(bh.getSize() == 5);
      REQUIRE(bh.findMin() == 1);
      bh.deleteMin();
      REQUIRE(bh.findMin() == 2);
      bh.deleteMin();
      REQUIRE(bh.findMin() == 3);
      bh.deleteMin();
      REQUIRE(bh.findMin() == 4);
      bh.deleteMin();
      REQUIRE(bh.findMin() == 5);
      bh.deleteMin();
      REQUIRE(bh.getSize() == 0);
    }
  }

}
