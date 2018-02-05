class Solution {
public:
    int rec(vector<vector<int>> &dp, vector<int> &nums, int left, int right) {
        if (left + 1 == right) return 0;
        int &ref = dp[left][right];
        if (ref != -1) return ref;
        ref = 0;
        for (int i = left + 1; i < right; i += 1) {
            ref = max(ref, nums[left] * nums[i] * nums[right] +
                      rec(dp, nums, left, i) +
                      rec(dp, nums, i, right)
                     );
        }
        return ref;
    }
    
    int maxCoins(vector<int>& nums) {
        vector<int> fix;
        fix.push_back(1);
        for (int x: nums) if (x > 0) fix.push_back(x);
        fix.push_back(1);
        vector<vector<int>> dp(fix.size(), vector<int>(fix.size(), -1));
        return rec(dp, fix, 0, fix.size() - 1);
    }
};
