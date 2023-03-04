#include <cstdlib>
#include <thread>
#include <vector>
#include "../lib/ThreadSafeVector.cpp"
#include "../lib/Semaphore.cpp"

class Demo {
private:
    std::vector<std::thread> _threads;
    int _leaders, _followers;
    Semaphore *_mutex;
    Semaphore *_leader, *_follower;
    Semaphore *_rendezvous;

public:
    // Creates a semaphore with an initial capacity of `semaphore_capacity` and
    // `n_threads` threads, access to a critical section inside each thread is controller
    // by at most `semaphore_capacity` concurrent threads.
    Demo(int n_threads) {
        ThreadSafeVector ts_messages;
        _leaders = _followers = 0;
        _mutex = new Semaphore(1);
        _leader = new Semaphore(0);
        _follower = new Semaphore(0);
        _rendezvous = new Semaphore(0);

        for (int i = 0; i < n_threads/2; i += 1) {
            std::thread t1(&Demo::Leader, this, std::ref(ts_messages));
            _threads.push_back(std::move(t1));
            std::thread t2(&Demo::Follower, this, std::ref(ts_messages));
            _threads.push_back(std::move(t2));
        }
        for (auto &t: _threads) {
            if (t.joinable()) {
                t.join();
            }
        }

        std::vector<std::string> messages = ts_messages.Clone();
        for (int i = 0; i < (int) messages.size(); i += 1) {
            printf("%s", messages[i].c_str());
        }
        assert((int) messages.size() == n_threads);
        for (int i = 0; i < (int) messages.size(); i += 2) {
            bool valid1 = messages[i+0] == "0" && messages[i+1] == "1";
            bool valid2 = messages[i+0] == "1" && messages[i+1] == "0";
            assert(valid1 || valid2);
        }
    }

    ~Demo() {
        free(_mutex);
        free(_follower);
        free(_leader);
        free(_rendezvous);
    }

    void Leader(ThreadSafeVector &v) {
        _mutex->Wait();
        if (_followers > 0) {
            // At least 1 leader and at least 1 follower, let the follower know that we can dance
            _followers -= 1;
            _follower->Signal();
        } else {
            // At least 1 leader but no followers, we must wait
            _leaders += 1;
            _mutex->Signal();
            _leader->Wait();
        }

        v.Push("0");
        _rendezvous->Wait();
        _mutex->Signal();

    }

    void Follower(ThreadSafeVector &v) {
        _mutex->Wait();
        if (_leaders > 0) {
            // At least 1 follower and at least 1 leader, let the follower know that we can dance
            _leaders -= 1;
            _leader->Signal();
        } else {
            // At least 1 follower but no leaders, we must wait
            _followers += 1;
            _mutex->Signal();
            _follower->Wait();
        }

        v.Push("1");
        _rendezvous->Signal();
    }
};

int main () {
    srand(time(NULL));
    Demo barrier(200);
    return 0;
}
