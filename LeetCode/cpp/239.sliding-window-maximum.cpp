class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> sol;
        if (!nums.size()) return sol;
        deque<int> q;
        for (int i = 0; i <= nums.size(); i += 1) {            
            if (i - k >= 0) {
                sol.push_back(q.front());
                if (nums[i - k] == q.front()) q.pop_front();
            }
            if (i != nums.size()) {
                while (q.size() && q.back() < nums[i]) q.pop_back();
                q.push_back(nums[i]);
            }
        }
        return sol;
    }
};
