class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        vector<int> bold(S.size(), 0);
        for (string w: words) {
            int it = 0;
            int next;
            while ((next = S.find(w, it)) != string::npos) {
                for (int i = 0; i < w.size(); i += 1) {
                    bold[i + next] = 1;
                }
                it = next + 1;
            }
        }
        
        string res;
        int status = 0;
        for (int i = 0; i < S.size(); i += 1) {
            if (bold[i] != status) {
                res += bold[i] ? "<b>" : "</b>";
                status = bold[i];
            }
            res += S[i];
        }
        if (bold[S.size() - 1]) res += "</b>";
        return res;
    }
};
