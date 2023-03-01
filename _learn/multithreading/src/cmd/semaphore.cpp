#include <cstdlib>
#include <thread>
#include <vector>
#include "../lib/Semaphore.cpp"

class CommonResource {
private:
    std::vector<std::thread> _threads;

public:
    // Creates a semaphore with an initial capacity of `semaphore_capacity` and
    // `n_threads` threads, access to a critical section inside each thread is controller
    // by at most `semaphore_capacity` concurrent threads.
    CommonResource(int semaphore_capacity, int n_threads) {
        Semaphore sem(semaphore_capacity);
        _threads.resize(n_threads);
        for (int i = 0; i < (int)_threads.size(); i += 1) {
            std::thread t(&CommonResource::Run, this, std::ref(sem), i);
            _threads[i] = std::move(t);
        }
        for (auto &t: _threads) {
            if (t.joinable()) {
                t.join();
            }
        }
    }

    void Run(Semaphore &s, int id) {
        unsigned long thread_id = std::hash<std::thread::id>{}(std::this_thread::get_id());
        s.Acquire();
        printf("thread_id=%zu id=%d\n", thread_id, id);
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        // std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 10));
        s.Release();
    }
};

int main () {
    srand(time(NULL));
    CommonResource cr(5, 10);
    return 0;
}
