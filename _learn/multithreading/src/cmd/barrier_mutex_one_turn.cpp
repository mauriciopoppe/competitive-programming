#include <cstdlib>
#include <thread>
#include <vector>
#include "../lib/ThreadSafeVector.cpp"

class Demo {
private:
    std::vector<std::thread> _threads;
    int _n;
    std::mutex _mu;
    std::condition_variable _cv;

public:
    // Creates a semaphore with an initial capacity of `semaphore_capacity` and
    // `n_threads` threads, access to a critical section inside each thread is controller
    // by at most `semaphore_capacity` concurrent threads.
    Demo(int n_threads) {
        _n = n_threads;
        _threads.resize(n_threads);

        ThreadSafeVector ts_messages;
        for (int i = 0; i < (int)_threads.size(); i += 1) {
            std::thread t(&Demo::Run, this, std::ref(ts_messages));
            _threads[i] = std::move(t);
        }
        for (auto &t: _threads) {
            if (t.joinable()) {
                t.join();
            }
        }

        std::vector<std::string> messages = ts_messages.Clone();
        assert(messages.size() == _threads.size() * 2);
        for (int i = 0; i < (int) messages.size() / 2; i += 1) {
            assert(messages[i] == "0");
        }
        for (int i = messages.size(); i < (int) messages.size(); i += 1) {
            assert(messages[i] == "1");
        }
    }

    void Run(ThreadSafeVector &v) {
        v.Push("0");
        {
            std::lock_guard<std::mutex> g(_mu);
            _n--;
            if (_n == 0) {
                _cv.notify_all();
            }
        }
        {
            std::unique_lock<std::mutex> g(_mu);
            while (_n != 0) {
                _cv.wait(g);
            }
        }
        v.Push("1");
    }
};

int main () {
    srand(time(NULL));
    Demo barrier(10);
    return 0;
}
