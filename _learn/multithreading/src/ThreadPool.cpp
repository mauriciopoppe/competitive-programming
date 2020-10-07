#include <iostream>
#include <queue>
#include <vector>
#include <thread>

class ThreadPool {
    std::queue<std::function<void()>> q;
    std::vector<std::thread> threads;
    std::mutex _m;
    std::condition_variable _cond;

    void ThreadRunner() {
        while (true) {
            std::function<void()> fn;

            // use the mutex over this block only
            {
                // wait until the queue has items
                std::unique_lock<std::mutex> g(_m);
                while (!q.size()) {
                    _cond.wait(g);
                }

                fn = std::move(q.front());
                q.pop();
            }

            fn();
        }
    }

public:
    ThreadPool(int n) {
        threads.resize(n);
        for (int i = 0; i < (int) threads.size(); i += 1) {
            std::thread t(&ThreadPool::ThreadRunner, std::ref(*this));
            threads[i] = std::move(t);
        }
    }

    void Enqueue(std::function<void()> fn) {
        std::unique_lock<std::mutex> g(_m);
        q.push(std::move(fn));
        _cond.notify_one();
    }

    void Start() {
        for (int i = 0; i < (int) threads.size(); i += 1) {
            if (threads[i].joinable()) {
                threads[i].join();
            }
        }
    }
};