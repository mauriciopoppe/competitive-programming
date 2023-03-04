#include <cstdlib>
#include <thread>
#include <vector>
#include "../lib/ThreadSafeVector.cpp"
#include "../lib/Semaphore.cpp"

class Demo {
private:
    std::vector<std::thread> _threads;
    int _n;
    int _count;

public:
    // Creates a semaphore with an initial capacity of `semaphore_capacity` and
    // `n_threads` threads, access to a critical section inside each thread is controller
    // by at most `semaphore_capacity` concurrent threads.
    Demo(int n_threads) {
        _count = 0;
        _n = n_threads;
        _threads.resize(n_threads);

        ThreadSafeVector ts_messages;
        Semaphore mutex(1);
        Semaphore barrier(0);
        for (int i = 0; i < (int)_threads.size(); i += 1) {
            std::thread t(&Demo::Run, this, std::ref(ts_messages), std::ref(mutex), std::ref(barrier));
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

    void Run(ThreadSafeVector &v, Semaphore &mutex, Semaphore &barrier) {
        v.Push("0");
        mutex.Wait();
        _count += 1;
        if (_count == _n) {
            barrier.Signal();
        }
        mutex.Signal();
        barrier.Wait();
        barrier.Signal();
        v.Push("1");
    }
};

int main () {
    srand(time(NULL));
    Demo barrier(10);
    return 0;
}
