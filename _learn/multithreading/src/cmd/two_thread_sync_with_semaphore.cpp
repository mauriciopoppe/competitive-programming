#include <cstdlib>
#include <thread>
#include <vector>
#include "../lib/Semaphore.cpp"

enum State { UNKNOWN, WRITTEN };

class CommonResource {
private:
    State v;

public:
    // Syncs 2 threads (reader, writer). Makes sure that the writing thread
    // completes before executing the reader thread.
    CommonResource() {
        v = UNKNOWN;
        Semaphore sem(0);
        std::thread reader_thread(&CommonResource::reader, this, std::ref(sem));
        std::thread writer_thread(&CommonResource::writer, this, std::ref(sem));
        if (reader_thread.joinable()) {
            reader_thread.join();
        }
        if (writer_thread.joinable()) {
            writer_thread.join();
        }
    }

    void writer(Semaphore &sem) {
        if (v != UNKNOWN) {
            printf("ERROR: value should be UNKNOWN");
            exit(1);
        }
        v = WRITTEN;
        sem.Signal();
    }

    void reader(Semaphore &sem) {
        sem.Wait();
        if (v == UNKNOWN) {
            printf("ERROR: value shouldn't be UNKNOWN");
            exit(1);
        }
    }
};

int main () {
    srand(time(NULL));
    CommonResource cr;
    return 0;
}
