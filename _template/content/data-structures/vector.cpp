#include <iostream>
#include <algorithm>
#include <cassert>

template <typename T>
class Vector {
  public:
    explicit Vector(int initialSize = 0) {
      _size = initialSize;
      _capacity = initialSize * 2 + 1;
      objects = new T[_capacity];
    }

    void resize(int newSize) {
      if (newSize > _capacity) {
        reserve(newSize * 2);
      }
    }

    void reserve(int newCapacity) {
      if (newCapacity < _capacity) {
        return;
      }
      // copy existing elements
      T *clone = new T[newCapacity];
      for (int i = 0; i < _size; i += 1) {
        clone[i] = objects[i];
      }
      _capacity = newCapacity;
      delete [] objects;
      objects = clone;
    }

    T operator[](int index) {
      return objects[index];
    }

    bool empty() const { return _size == 0; }

    int size() const { return _size; }

    int capacity() const { return _capacity; }

    void push_back(const T x) {
      if (_size == _capacity) {
        // + 1 comes from accessing objects[size()]
        std::cout << "resizing\n";
        reserve(2 * _capacity + 1);
      }
      objects[_size++] = x;
      // print();
    }

    void print() {
      std::cout << "[";
      for (int i = 0; i < _size; i += 1) {
        std::cout << ((i > 0) ? " " : "") << objects[i];
      }
      std::cout << "]\n";
    }

    void pop_back() {
      _size--;
    }

    T & back() {
      return objects[_size - 1];
    }

    T *begin() {
      return &objects[0];
    }

    T *end() {
      return &objects[size()];
    }

  private:
    int _size;
    int _capacity;
    T *objects;
};

int main() {
  Vector<int> v;
  assert(v.size() == 0);
  v.push_back(1);
  v.push_back(2);
  assert(v.back() == 2);
  assert(v[0] == 1);
  assert(v[1] == 2);

  for (int *i = v.begin(); i != v.end(); i++) {
    assert(*i == 1 || *i == 2);
  }

  v.pop_back();
  assert(v.back() == 1);
}
