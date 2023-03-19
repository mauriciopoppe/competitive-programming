#include <cassert>
#include <cstdlib>
#include <thread>
#include <vector>
#include <map>
#include "../lib/ThreadSafeVector.cpp"
#include "../lib/Barrier.cpp"

/*

Requirements:

P0 Keep a graph of pages seen.
P0 Prevent getting throttled (1st iteration with semaphore, 2nd iteration with threadpool).

*/

using namespace std;

class WebCrawler {
private:
    map<string, bool> _seen;
    mutex _m;

    void ScanSingle(map<string, vector<string>> &pages, const string &page) {
        {
            lock_guard<mutex> g(_m);
            if (_seen[page]) {
                return;
            }
            printf("seen=%s\n", page.c_str());
            _seen[page] = true;
        }

        // simulate read a page
        vector<string> links = pages[page];

        vector<thread> threads;
        for (int i = 0; i < (int) links.size(); i += 1) {
            thread t(&WebCrawler::ScanSingle, this, ref(pages), ref(links[i]));
            threads.push_back(std::move(t));
        }

        for (int i = 0; i < (int) links.size(); i += 1) {
            if (threads[i].joinable()) {
                threads[i].join();
            }
        }
    }

public:
    // Creates a semaphore with an initial capacity of `semaphore_capacity` and
    // `n_threads` threads, access to a critical section inside each thread is controller
    // by at most `semaphore_capacity` concurrent threads.
    WebCrawler() { }

    void Scan(map<string, vector<string>> &pages) {
        vector<thread> threads;
        for (auto &it: pages) {
            thread t(&WebCrawler::ScanSingle, this, ref(pages), ref(it.first));
            threads.push_back(std::move(t));
        }
        for (int i = 0; i < (int) pages.size(); i += 1) {
            if (threads[i].joinable()) {
                threads[i].join();
            }
        }
    }

    map<string, bool> GetSeen() {
        return _seen;
    }
};

int main () {
    srand(time(NULL));
    WebCrawler web_crawler;

    map<string, vector<string>> pages;
    pages["a"] = vector<string> {"a", "b", "c", "d", "e", "f", "z"};
    pages["b"] = vector<string> {"a", "c", "z"};
    pages["c"] = vector<string> {"d"};
    pages["d"] = vector<string> {"d", "a"};
    pages["e"] = vector<string> {"b", "c"};
    pages["z"] = vector<string> {"a", "e"};
    web_crawler.Scan(pages);

    auto seen = web_crawler.GetSeen();
    vector<string> expected = {"a", "b", "c", "d"};
    for (auto &t: expected) {
        assert(seen[t]);
    }

    return 0;
}
