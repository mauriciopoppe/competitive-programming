struct Event {
    int type;
    int height;
    int x;
    Event(int _type, int _height, int _x) {
        type = _type;
        height = _height;
        x = _x;
    }
    
    bool operator<(const Event &other) const {
        if (x != other.x) return x < other.x;
        // if (type != other.type) return type > other.type;
        return height <= other.height;
    }
};

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> sol;
        if (!buildings.size()) return sol;
        
        vector<Event> events;
        for (auto ev: buildings) {
            events.push_back(Event(0, ev[2], ev[0]));
            events.push_back(Event(1, ev[2], ev[1]));
        }
        sort(events.begin(), events.end());        
        map<int, int> h;
        int lh = -1;
        int lx = -1;
        for (int i = 0; i < events.size(); ) {
            int nx = events[i].x;
            while (i < events.size() && nx == events[i].x) {
                Event e = events[i++];
                if (e.type == 0) {
                    h[e.height]++;
                } else {
                    h[e.height]--;
                    if (!h[e.height]) h.erase(e.height);
                }
            }
            int nh = h.size() ? h.rbegin()->first : 0;
            if (nh != lh) {
                sol.push_back({ lx, lh });
                lx = nx;
                lh = nh;
            }
        }
        sol.erase(sol.begin());
        sol.push_back({ lx, 0 });
        return sol;
    }
};
