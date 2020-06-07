typedef pair<int, string> pis;

class Solution {
public:
    vector<string> solve(unordered_map<string, vector<string>> &dp, string s, vector<string> &wordDict) {
        if (dp.count(s)) return dp[s];

        vector<string> out;
        for (int i = 0; i < wordDict.size(); i += 1) {
            string &w = wordDict[i];

            if (s == w) out.push_back(w);
            else if (w.size() < s.size() && s.compare(0, w.size(), w) == 0) {
                string left = w;
                vector<string> right = solve(dp, s.substr(left.size()), wordDict);
                for (auto r: right) {
                    out.push_back(left + " " + r);
                }
            }
        }
        return dp[s] = out;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> dp;
        return solve(dp, s, wordDict);
    }
};