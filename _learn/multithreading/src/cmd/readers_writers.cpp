#include <cstdlib>
#include <thread>
#include <vector>
#include <queue>
#include <map>
#include <functional>
#include "../lib/ThreadSafeVector.cpp"
#include "../lib/Semaphore.cpp"
#include "../lib/Barrier.cpp"

class Demo {
private:
    std::vector<std::thread> _threads;
    Semaphore *_mutex;
    Semaphore *_room_empty;
    int readers;

public:
    Demo(int n_readers, int n_writers) {
        readers = 0;
        _mutex = new Semaphore(1);
        _room_empty = new Semaphore(1);

        ThreadSafeVector<int> ts_messages;

        // the barrier makes all the thread start at approximately the same time.
        Barrier b(n_writers + n_readers);
        for (int i = 0; i < n_writers; i += 1) {
            std::thread t1(&Demo::Writer, this, std::ref(ts_messages), std::ref(b));
            _threads.push_back(std::move(t1));
        }
        for (int i = 0; i < n_readers; i += 1) {
            std::thread t1(&Demo::Reader, this, std::ref(ts_messages), std::ref(b));
            _threads.push_back(std::move(t1));
        }
        for (auto &t: _threads) {
            if (t.joinable()) {
                t.join();
            }
        }
        std::vector<int> messages = ts_messages.Clone();
    }

    ~Demo() {
        free(_mutex);
        free(_room_empty);
    }

    void Reader(ThreadSafeVector<int> &v, Barrier &b) {
        b.Wait();

        _mutex->Wait();
        if (readers == 0) {
            _room_empty->Wait();
        }
        readers += 1;
        _mutex->Signal();

        {
            printf("Read critical section\n");
        }

        _mutex->Wait();
        readers -= 1;
        if (readers == 0) {
            _room_empty->Signal();
        }
        _mutex->Signal();
    }

    void Writer(ThreadSafeVector<int> &v, Barrier &b) {
        b.Wait();

        _room_empty->Wait();
        {
            printf("Write critical section\n");
        }
        _room_empty->Signal();
    }
};

int main () {
    srand(time(NULL));
    int n_readers = 100;
    int n_writers = 10;
    Demo readers_writers(
        n_readers,
        n_writers
    );
    return 0;
}
