class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> v(10001, 0);
        for (int i = 0; i < nums.size(); i += 1) v[nums[i]]++;
        vector<int> dp(10001, 0);
        int mx = 0;
        for (int i = 1; i <= 10000; i += 1) {
            dp[i] = max(v[i] * i + (i - 2 >= 0 ? dp[i - 2] : 0), dp[i - 1]);
            mx = max(mx, dp[i]);
        }
        return mx;
    }
};
