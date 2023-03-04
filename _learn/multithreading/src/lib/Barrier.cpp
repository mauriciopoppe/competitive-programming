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
    }

    void Wait() {
        _mutex->Acquire();
        _current += 1;
        if (_current == _n) {
            _turnstile2->Acquire();
            _turnstile->Release();
        }
        _mutex->Release();

        _turnstile->Acquire();
        _turnstile->Release();

        _mutex->Acquire();
        _current -= 1;
        if (_current == 0) {
            _turnstile->Acquire();
            _turnstile2->Release();
        }
        _mutex->Release();

        _turnstile2->Acquire();
        _turnstile2->Release();
    }
};
