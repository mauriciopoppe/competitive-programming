class Solution {
public:
    int rec(vector<int> &prices, vector<int> &dp, int i) {
        if (i >= prices.size()) return 0;
        int &best = dp[i];
        if (best != -1) return best;
        best = 0;
        int taken = prices[i];
        int best_so_far = 0;
        for (int j = i + 1; j < prices.size(); j++) {
            if (prices[j] - taken > best_so_far) {
                best_so_far = prices[j] - taken;
                best = max(best_so_far + rec(prices, dp, j + 2), best);
            }
            taken = min(taken, prices[j]);
        }
        return best;
    }
        
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size(), -1);
        return rec(prices, dp, 0);
    }
};
