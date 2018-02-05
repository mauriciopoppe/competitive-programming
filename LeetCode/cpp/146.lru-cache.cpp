
class LRUCache {
public:
    list<pair<int, int>> lru;
    unordered_map<int, list<pair<int, int>>::iterator> itoit;
    int max_capacity;
    
    LRUCache(int capacity) {
        max_capacity = capacity;
    }
    
    int get(int key) {
        if (!itoit.count(key)) return -1;
        push_to_top(key);
        return itoit[key]->second;
    }
    
    void put(int key, int value) {
        if (itoit.count(key)) {
            auto it = itoit[key];
            it->second = value;
            push_to_top(key);
        } else {
            lru.push_front({ key, value });
            itoit[key] = lru.begin();
        }
        if (lru.size() > max_capacity) {
            itoit.erase(lru.back().first);
            lru.pop_back();
        }
    }
    
    void push_to_top(int key) {
        list<pair<int,int>>::iterator it = itoit[key];
        auto p = *it;
        lru.erase(it);
        lru.push_front(p);
        itoit[key] = lru.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
