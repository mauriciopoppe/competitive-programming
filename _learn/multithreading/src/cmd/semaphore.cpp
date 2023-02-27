#include <cstdlib>
#include <thread>
#include <vector>
#include "../lib/Semaphore.cpp"

class CommonResource {
private:
    std::vector<std::thread> _threads;

public:
    void Run(Semaphore &s, int id) {
        unsigned long thread_id = std::hash<std::thread::id>{}(std::this_thread::get_id());
        s.Acquire();
        printf("thread_id=%zu id=%d\n", thread_id, id);
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 10));
        s.Release();
    }

    CommonResource() {
        Semaphore sem(5);
        _threads.resize(100);
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
};

int main () {
    srand(time(NULL));
    CommonResource cr;
    return 0;
}
