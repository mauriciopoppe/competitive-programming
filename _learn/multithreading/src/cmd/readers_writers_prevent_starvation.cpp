#include <cstdlib>
#include <thread>
#include <vector>
#include <queue>
#include <map>
#include <functional>
#include "../lib/ThreadSafeVector.cpp"
#include "../lib/Semaphore.cpp"
#include "../lib/Barrier.cpp"
#include "../lib/Lightswitch.cpp"

class Demo {
private:
    std::vector<std::thread> _threads;
    Semaphore *_room_empty;
    Semaphore *_writer_arrived;
    Semaphore *_turnstile;

public:
    Demo(int n_readers, int n_writers) {
        _room_empty = new Semaphore(1);
        _turnstile = new Semaphore(1);

        ThreadSafeVector<int> ts_messages;
        Lightswitch read_switch;

        // the barrier makes all the thread start at approximately the same time.
        Barrier b(n_writers + n_readers);
        for (int i = 0; i < n_writers; i += 1) {
            std::thread t1(&Demo::Writer, this, std::ref(ts_messages), std::ref(b), std::ref(read_switch));
            _threads.push_back(std::move(t1));
        }
        for (int i = 0; i < n_readers; i += 1) {
            std::thread t1(&Demo::Reader, this, std::ref(ts_messages), std::ref(b), std::ref(read_switch));
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
        free(_room_empty);
        free(_writer_arrived);
    }

    void Reader(ThreadSafeVector<int> &v, Barrier &b, Lightswitch &read_switch) {
        b.Wait();
        _turnstile->Wait();
        _turnstile->Signal();

        read_switch.Lock(_room_empty);
        {
            printf("Read critical section\n");
        }
        read_switch.Unlock(_room_empty);
    }

    void Writer(ThreadSafeVector<int> &v, Barrier &b, Lightswitch &read_switch) {
        b.Wait();
        _turnstile->Wait();
            _room_empty->Wait();
            {
                printf("Write critical section\n");
            }
        _turnstile->Signal();

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
