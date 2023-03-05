#include <cstdlib>
#include <thread>
#include <vector>
#include <queue>
#include <map>
#include <functional>
#include "../lib/ThreadSafeVector.cpp"
#include "../lib/Semaphore.cpp"

typedef std::function<void()> Task;

class Demo {
private:
    std::vector<std::thread> _producers;
    std::vector<std::thread> _consumers;
    Semaphore *_mutex;
    Semaphore *_items, *_spaces;
    int _messages_left;
    std::queue<Task> _tasks;

public:
    Demo(int n_producers, int n_consumers, int buffer) {
        _mutex = new Semaphore(1);
        _items = new Semaphore(0);
        _spaces = new Semaphore(buffer);
        _messages_left = n_producers;

        ThreadSafeVector<int> ts_messages;
        for (int i = 0; i < n_producers; i += 1) {
            std::thread t1(&Demo::Producer, this, std::ref(ts_messages), i);
            _producers.push_back(std::move(t1));
        }
        for (int i = 0; i < n_consumers; i += 1) {
            std::thread t1(&Demo::Consumer, this);
            _consumers.push_back(std::move(t1));
        }
        for (auto &t: _producers) {
            if (t.joinable()) {
                t.join();
            }
        }
        for (auto &t: _consumers) {
            if (t.joinable()) {
                t.join();
            }
        }

        std::vector<int> messages = ts_messages.Clone();
        std::map<int, int> seen;
        for (int i = 0; i < (int) messages.size(); i += 1) {
            seen[messages[i]] = 1;
            // printf("%d", messages[i]);
        }
        assert((int) messages.size() == n_producers);
        assert((int) seen.size() == n_producers);
    }

    ~Demo() {
        free(_mutex);
        free(_items);
        free(_spaces);
    }

    void Producer(ThreadSafeVector<int> &v, int i) {
        Task fn = [&v, i]() { v.Push(i); };
        _spaces->Wait();

        _mutex->Wait();
        _tasks.push(fn);
        _mutex->Signal();

        _items->Signal();
    }

    void Consumer() {
        Task fn;
        _items->Wait();

        _mutex->Wait();
        fn = _tasks.front();
        _tasks.pop();
        _mutex->Signal();

        _spaces->Signal();
        fn();
    }
};

int main () {
    srand(time(NULL));
    int n_producers = 100;
    int n_consumers = 100;
    int buffer = 5;
    Demo producer_consumer(
        n_producers,
        n_consumers,
        buffer
    );
    return 0;
}
