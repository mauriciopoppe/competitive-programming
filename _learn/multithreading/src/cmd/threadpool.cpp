#include "../lib/ThreadPool.cpp"

void ExampleThreadpool() {
    std::hash<std::thread::id> hasher;

    ThreadPool threadPool(5);
    for (int i = 0; i < 15; i += 1) {
        threadPool.Enqueue([i, hasher]() {
            printf("Task: %d, Thread: %zu\n", i, hasher(std::this_thread::get_id()));
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        });
    }
}

int main () {
    ExampleThreadpool();
    return 0;
}
