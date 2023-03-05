#include <vector>
#include <mutex>

template <class T>
class ThreadSafeVector {
    std::mutex _mu;
    std::vector<T> v;

public:
    void Push(T item) {
        std::lock_guard<std::mutex> g(_mu);
        v.push_back(item);
    }

    void Pop() {
        std::lock_guard<std::mutex> g(_mu);
        v.pop_back();
    }

    int Size() {
        return v.size();
    }

    std::vector<T> Clone() {
        std::lock_guard<std::mutex> g(_mu);
        std::vector<T> out = v;
        return out;
    }
};

