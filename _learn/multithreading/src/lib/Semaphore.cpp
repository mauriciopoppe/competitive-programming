#include <mutex>
#include <condition_variable>

// Semaphore guards the concurrent access to a critical zone up to _max_requests threads.
// If there are more than `_max_requests` trying to access the critical zone at the same
// time then the semaphore will block until there are concurrent access spots available.
class Semaphore {
private:
	std::mutex _m;
	std::condition_variable _cv;
	int _capacity;
public:
	Semaphore(int initial_capacity) {
		_capacity = initial_capacity;
	}

	void Acquire() {
		std::unique_lock<std::mutex> lock(_m);
		while (_capacity == 0) {
			_cv.wait(lock);
		}
		_capacity -= 1;
	}

	void Release() {
		std::lock_guard<std::mutex> lock(_m);
		_capacity += 1;
		_cv.notify_all();
	}
};
