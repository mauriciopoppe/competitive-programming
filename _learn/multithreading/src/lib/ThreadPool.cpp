#include <algorithm>
#include <chrono>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <queue>
#include <ratio>
#include <thread>
#include <vector>

class ThreadPool {
	// the tasks to be executed in the threadPool
	std::queue<std::function<void()>> q;

	// the threads created in the threadPool
	std::vector<std::thread> threads;

	// the mutex that controls access to the tasks queue
	std::mutex _m;

	// the condition variable that pauses a thread if there are no tasks pending
	std::condition_variable _cond;

	// terminated is true if the ThreadPool instance goes out of scope.
	bool _shutdown;

	// _running is the number of tasks currently _running in the ThreadPool.
	unsigned int _running;

	void ThreadRunner() {
		// unsigned long thread_id = std::hash<std::thread::id>{}(std::this_thread::get_id());
		while (true) {
			std::function<void()> fn;

			// use the mutex over this block only
			{
				// wait until the queue has items
				std::unique_lock<std::mutex> g(_m);

				while (!q.size()) {
					if (_shutdown && _running == 0) {
						// printf("Shutdown completed thread=%zu\n", thread_id);
						_cond.notify_one();
						return;
					}
					// printf("waiting for lock thread=%zu running=%d shutdown=%d\n", thread_id, _running, _shutdown);
					_cond.wait(g);
					// printf("lock acquired thread=%zu\n", thread_id);
				}

				fn = std::move(q.front());
				q.pop();
				_running += 1;
			}

			// guaranteed to exist, it can't be a reference to something invalid
			// because the block above will pull an item from the queue if it exists
			fn();
			{
				std::unique_lock<std::mutex> g(_m);
				_running -= 1;
			}
		}
	}

public:
	ThreadPool(int n) {
		// printf("Starting %d threads\n", n);
		threads.resize(n);
		_shutdown = false;
		for (int i = 0; i < (int)threads.size(); i += 1) {
			// https://www.justsoftwaresolutions.co.uk/threading/multithreading-in-c++0x-part-3.html
			std::thread t(&ThreadPool::ThreadRunner, std::ref(*this));
			threads[i] = std::move(t);
		}
	}

	// Destructor ensures that there are no tasks left executing in the threadpool
	~ThreadPool() {
		{
			std::unique_lock<std::mutex> g(_m);
			_shutdown = true;
		}
		// printf("Calling join on all threads\n");
		for (int i = 0; i < (int)threads.size(); i += 1) {
			if (threads[i].joinable()) {
				threads[i].join();
			}
		}
	}


	void Enqueue(std::function<void()> fn) {
		// any modification to the queue is controlled by the mutex
		std::unique_lock<std::mutex> g(_m);
		q.push(std::move(fn));
		_cond.notify_one();
	}
};
