#include <iostream>
#include <queue>
#include <vector>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>

class ThreadPool {
    // the jobs to be executed in the threadPool
    std::queue<std::function<void()>> q;

    // the threads created in the threadPool
    std::vector<std::thread> threads;

    // the mutex that controls access to the jobs queue
    std::mutex _m;

    // the condition variable that pauses a thread if there are no jobs pending
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

            // guaranteed to exist, it can't be a reference to something invalid
            // because the block above will pull an item from the queue if it exists
            fn();
        }
    }

public:
    ThreadPool(int n) {
        threads.resize(n);
        for (int i = 0; i < (int) threads.size(); i += 1) {
            // https://www.justsoftwaresolutions.co.uk/threading/multithreading-in-c++0x-part-3.html
            std::thread t(&ThreadPool::ThreadRunner, std::ref(*this));
            threads[i] = std::move(t);
        }
    }

    void Enqueue(std::function<void()> fn) {
        // any modification to the queue is controlled by the mutex
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