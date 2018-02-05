/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct Event {
    int type;
    int v;
    int id;
    Event(int id, int v, int type):
        id(id), v(v), type(type) {}
    
    bool operator<(const Event &other) const {
        if (v != other.v) return v < other.v;
        return type < other.type;
    }
};

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& avails) {
        vector<Event> v;
        for (int i = 0; i < avails.size(); i += 1) {
            for (Interval &it: avails[i]) {
                v.push_back(Event(i, it.start, 0));
                v.push_back(Event(i, it.end, 1));
            }
        }
        sort(v.begin(), v.end());
        set<int> total;        
        vector<Interval> all;
        int start = -1, end = -1;
        for (int i = 0; i < v.size(); i += 1) {
            Event &ev = v[i];
            if (ev.type == 0) {
                if (total.size() == 0 && i) {
                    end = ev.v;
                }
                total.insert(ev.id);
            } else {
                total.erase(ev.id);
                if (total.size() == 0) {
                    start = ev.v;
                }
            }
            if (start >= 0 && end >= 0) {
                all.push_back(Interval(start, end));
                start = -1;
                end = -1;
            }
        }
        return all;
    }
};
