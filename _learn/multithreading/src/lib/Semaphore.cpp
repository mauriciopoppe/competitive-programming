#include <mutex>
#include <condition_variable>

// Semaphore guards the concurrent access to a critical zone up to _max_requests threads.
// If there are more than `_max_requests` trying to access the critical zone at the same
// time then the semaphore will block until there are concurrent access spots available.
class Semaphore {
private:
	std::mutex _m;
	std::condition_variable _cv;
	int _max_requests;
	int _current_requests;
public:
	Semaphore(int max_requests) {
		_max_requests = max_requests;
		_current_requests = 0;
	}

	void Acquire() {
		std::unique_lock<std::mutex> lock(_m);
		while (_current_requests == _max_requests) {
			_cv.wait(lock);
		}
		_current_requests += 1;
	}

	void Release() {
		std::lock_guard<std::mutex> lock(_m);
		_current_requests -= 1;
		_cv.notify_all();
	}
};
