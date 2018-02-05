class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), [](pair<int, int> p1, pair<int, int> p2) {
            if (p1.first != p2.first) return p1.first > p2.first;
            return p1.second < p2.second;
        });
        vector<pair<int, int>> sol;
        for (auto t: people) {
            sol.insert(sol.begin() + t.second, t);
        }
        return sol;
    }
};
