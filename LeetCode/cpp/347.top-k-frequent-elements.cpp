bool Cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for (auto t: nums) ++m[t];
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        for (auto it: m) {
            int num = it.first;
            int cnt = it.second;
            pq.push({ cnt, num });
            if (pq.size() > k) pq.pop();
        }
        vector<int> v;
        while(pq.size()) {
            int n = pq.top().second;
            v.push_back(n);
            pq.pop();
        }
        return v;
    }
};
