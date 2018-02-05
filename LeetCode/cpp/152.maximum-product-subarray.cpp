class Solution {
public:
    void solve(vector<int> &nums, vector<int> &s, int &mx) {
        for (int z = 1; z < s.size(); z += 1) {
            int lo = s[z - 1];
            int hi = s[z];
            if (lo + 1 == hi) continue;
            vector<int> neg_pos;
            for (int i = lo + 1; i < hi; i += 1) {
                if (nums[i] < 0) neg_pos.push_back(i);
            }
            if (neg_pos.size() % 2 == 0) {
                int p = 1;
                for (int i = lo + 1; i < hi; i += 1) p *= nums[i];
                mx = max(p, mx);
            } else {
                if (neg_pos.front() + 1 < hi) {
                    int p = 1;
                    for (int i = neg_pos.front() + 1; i < hi; i += 1) p *= nums[i];
                    mx = max(p, mx);
                }
                if (neg_pos.back() - 1 >= lo + 1) {
                    int p = 1;
                    for (int i = lo + 1; i < neg_pos.back(); i += 1) p *= nums[i];
                    mx = max(p, mx);
                }
            }
        }
    }
    
    int maxProduct(vector<int>& nums) {
        if (!nums.size()) return 0;
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> s;
        s.push_back(-1);
        for (int i = 0; i < nums.size(); i += 1) {
            if (!nums[i]) s.push_back(i);
        }
        s.push_back(nums.size());
        solve(nums, s, mx);
        return mx;
    }
};
