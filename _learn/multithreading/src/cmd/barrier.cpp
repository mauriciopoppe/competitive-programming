#include <cstdlib>
#include <thread>
#include <vector>
#include "../lib/ThreadSafeVector.cpp"
#include "../lib/Barrier.cpp"

class Demo {
private:
    std::vector<std::thread> _threads;

public:
    // Creates a semaphore with an initial capacity of `semaphore_capacity` and
    // `n_threads` threads, access to a critical section inside each thread is controller
    // by at most `semaphore_capacity` concurrent threads.
    Demo(int n_threads) {
        _threads.resize(n_threads);

        ThreadSafeVector ts_messages;
        Barrier barrier(n_threads);
        for (int i = 0; i < n_threads; i += 1) {
            std::thread t(&Demo::Run, this, std::ref(ts_messages), std::ref(barrier));
            _threads[i] = std::move(t);
        }
        for (auto &t: _threads) {
            if (t.joinable()) {
                t.join();
            }
        }

        std::vector<std::string> messages = ts_messages.Clone();
        assert((int) messages.size() == n_threads*3);
        for (int i = 0; i < (int) messages.size() / 3; i += 1) {
            assert(messages[i + n_threads*0] == "0");
            assert(messages[i + n_threads*1] == "1");
            assert(messages[i + n_threads*2] == "2");
        }
    }

    void Run(ThreadSafeVector &v, Barrier &b) {
        v.Push("0");
        b.Wait();
        v.Push("1");
        b.Wait();
        v.Push("2");
    }
};

int main () {
    srand(time(NULL));
    Demo barrier(10);
    return 0;
}
