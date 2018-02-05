class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> in_deg(numCourses, 0);
        for (auto it: prerequisites) {
            in_deg[it.first]++;
        }
        queue<int> taken;
        for (int i = 0; i < numCourses; i += 1) {
            if (!in_deg[i]) taken.push(i);
        }
        while (taken.size()) {
            int top = taken.front();
            taken.pop();
            numCourses--;
            for (auto it: prerequisites) {
                int from = it.second;
                int to = it.first;
                if (from == top) {
                    in_deg[to]--;
                    if (!in_deg[to]) taken.push(to);
                }
            }
        }
        return numCourses == 0;
    }
};
