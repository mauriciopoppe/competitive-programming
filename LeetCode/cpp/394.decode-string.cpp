class Solution {
public:
    string rec(string s, int &i) {
        int n = 0;
        while (i < s.size() && isdigit(s[i])) {
            n = n * 10 + s[i++] - '0';
        }
        i++;    // skip [
        string res = "";
        while (i < s.size() && s[i] != ']') {
            if (isalpha(s[i])) res += s[i++];
            else {
                res += rec(s, i);
            }
        }        
        i++;    // skip ]
        
        string total = "";
        for (int j = 0; j < n; j += 1) {
            total += res;
        }
        return total;
    }

    string decodeString(string s) {
        int i = 0;
        string result = "";
        while (i < s.size()) {
            if (isdigit(s[i])) {
                result += rec(s, i);
                continue;
            } 
            if (isalpha(s[i])) {
                result += s[i++];
                continue;
            }
        }
        return result;
    }
};
