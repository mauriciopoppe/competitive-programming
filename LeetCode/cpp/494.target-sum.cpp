class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<map<int, int>> dp(nums.size() + 1, map<int, int>());
        dp[0][0] = 1;
        for (int i = 0; i < nums.size(); i += 1) {
            for (auto it: dp[i]) {
                int n = it.first;
                int cnt = it.second;
                dp[i + 1][n + nums[i]] += cnt;
                dp[i + 1][n - nums[i]] += cnt;
            }
        }
        return dp[nums.size()][S];
    }
};
