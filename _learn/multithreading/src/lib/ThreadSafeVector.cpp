#include <vector>
#include <mutex>

class ThreadSafeVector {
    std::mutex _mu;
    std::vector<std::string> v;

public:
    void Push(std::string str) {
        std::lock_guard<std::mutex> g(_mu);
        v.push_back(str);
    }

    void Pop() {
        std::lock_guard<std::mutex> g(_mu);
        v.pop_back();
    }

    int Size() {
        return v.size();
    }

    std::vector<std::string> Clone() {
        std::lock_guard<std::mutex> g(_mu);
        std::vector<std::string> out = v;
        return out;
    }
};

