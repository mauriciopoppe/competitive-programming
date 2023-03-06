#ifndef LIGHTSWITCH_GUARD
#define LIGHTSWITCH_GUARD
#include "./Semaphore.cpp"

// Semaphore guards the concurrent access to a critical zone up to _max_requests threads.
// If there are more than `_max_requests` trying to access the critical zone at the same
// time then the semaphore will block until there are concurrent access spots available.
class Lightswitch {
private:
    int _counter;
    Semaphore *_mutex;
public:
	Lightswitch() {
        _counter = 0;
        _mutex = new Semaphore(1);
	}

	void Lock(Semaphore *other) {
        _mutex->Wait();
        _counter += 1;
        if (_counter == 1) {
            other->Wait();
        }
        _mutex->Signal();
	}

	void Unlock(Semaphore *other) {
        _mutex->Wait();
        _counter -= 1;
        if (_counter == 0) {
            other->Signal();
        }
        _mutex->Signal();
	}
};
#endif
