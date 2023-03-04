#include "./Semaphore.cpp"

class Barrier {
    Semaphore *_mutex;
    Semaphore *_turnstile;
    Semaphore *_turnstile2;
    int _n;
    int _current;

public:
    Barrier(int n) {
        _n = n;
        _current = 0;
        _mutex = new Semaphore(1);
        _turnstile = new Semaphore(0);
        _turnstile2 = new Semaphore(1);
    }

    ~Barrier() {
        free(_mutex);
        free(_turnstile);
        free(_turnstile2);
    }

    void Wait() {
        _mutex->Wait();
        _current += 1;
        if (_current == _n) {
            _turnstile2->Wait();
            _turnstile->Signal();
        }
        _mutex->Signal();

        _turnstile->Wait();
        _turnstile->Signal();

        _mutex->Wait();
        _current -= 1;
        if (_current == 0) {
            _turnstile->Wait();
            _turnstile2->Signal();
        }
        _mutex->Signal();

        _turnstile2->Wait();
        _turnstile2->Signal();
    }
};
