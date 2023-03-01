#include <thread>
#include <vector>
#include <cstdlib>
#include <cassert>
#include "../lib/Semaphore.cpp"

class Demo {
private:
    std::vector<std::string> statements;
public:
    // Rendezvous problem in the little book of semaphores.
    //
    // given:
    // thread a: statement 1
    // thread a: statement 2
    // thread b: statement 1
    // thread b: statement 2
    //
    // Ensure that:
    // - a1 happens before b2 (a1 > b2)
    // - b1 happens before a2 (b1 > a2)
    //
    // Possible solution:
    // - a1 > b1 > b2 > a2
    Demo() {
        Semaphore waitA(0);
        Semaphore waitB(0);
        auto handlerA = [&]() {
            statements.push_back("a1");
            waitA.Release();
            waitB.Acquire();
            statements.push_back("a2");
        };
        auto handlerB = [&]() {
            waitA.Acquire();
            statements.push_back("b1");
            statements.push_back("b2");
            waitB.Release();
        };
        std::thread ta(handlerA);
        std::thread tb(handlerB);
        if (ta.joinable()) {
            ta.join();
        }
        if (tb.joinable()) {
            tb.join();
        }
        assert(statements.size() == 4);
        std::vector<std::string> expected = {"a1", "b1", "b2", "a2"};
        for (int i = 0; i < (int) statements.size(); i += 1) {
            assert(statements[i] == expected[i]);
        }
    }
};

int main () {
    srand(time(NULL));
    Demo cr;
    return 0;
}
