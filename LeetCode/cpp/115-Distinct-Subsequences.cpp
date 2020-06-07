typedef long long ll;

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<ll>> dp(t.size() + 1, vector<ll>(s.size() + 1, 0));
        ll best = 0;
        dp[0][0] = 1;
        for (int it = 1; it <= t.size(); it += 1) {
            vector<ll> pre(s.size() + 1, 0);
            for (int i = 0; i <= s.size(); i += 1) {
                pre[i] += (i-1>=0?pre[i-1]:0) + dp[it-1][i];
            }
            for (int is = 1; is <= s.size(); is += 1) {
                if (s[is - 1] == t[it - 1]) {
                    dp[it][is] += pre[is-1];
                    if (it == t.size()) best += dp[it][is];
                }
            }
        }
        return best;
    }
};