class Solution {
public:
    int numSquares(int n) {
        int INF = 1e9;
        vector<int> dp(n + 1, INF);
        dp[0] = 0;
        for (int j = 1; j * j <= n; j += 1) {
            for (int i = j * j; i <= n; i += 1) {
                dp[i] = min(dp[i - j * j] + 1, dp[i]);
            }
        }
        return dp[n];
    }
};
