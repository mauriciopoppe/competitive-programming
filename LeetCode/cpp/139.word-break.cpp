class Solution {
public:
    bool traverse(string s, set<string> &words, map<int, bool> &dp) {
        if (s == "") return true;
        if (dp.count(s.size())) return dp[s.size()];
        bool &found = dp[s.size()];
        for (int k = 1; !found && k <= s.size(); k += 1) {
            bool left = words.count(s.substr(0, k));
            bool right = traverse(s.substr(k), words, dp);
            if (left && right) found = true;
        }
        return found;
    }
        
    bool wordBreak(string s, vector<string>& wordDict) {
        map<int, bool> dp;
        set<string> words(wordDict.begin(), wordDict.end());
        return traverse(s, words, dp);
    }
};
