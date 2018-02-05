class Solution {
public:
    
    int countSubstrings(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        int total = s.size();
        for (int i = 0; i < s.size(); i += 1) dp[i][i] = 1;
        for (int i = 1; i < s.size(); i += 1) {
            dp[i - 1][i] = s[i - 1] == s[i];
            total += dp[i - 1][i];
        }
        for (int len = 3; len <= s.size(); len += 1) {
            for (int i = 0, j = len - 1; j < s.size(); i += 1, j += 1) {
                dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
                total += dp[i][j];
            }
        }
        return total;
    }
};
