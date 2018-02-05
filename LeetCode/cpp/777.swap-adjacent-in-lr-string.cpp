/*
 * strategy: two pointers with two conditions, explained in https://leetcode.com/articles/swap-adjacent-in-lr-string/
 * time-complexity: O(n), n is the size of the string
 * space-complexity: O(1)
 * tags: [strings, two-pointers]
 */
class Solution {
public:
    string rep(string s) {
        string res;
        for (char c: s) {
            if (c != 'X') {
                res += c;
            }
        }
        return res;
    }

    bool canTransform(string start, string end) {
        if (rep(start) != rep(end)) return false;
        int t = 0;
        for (int i = 0; i < start.size(); i += 1) {
            if (start[i] == 'R') {
                while (end[t] != 'R') t++;
                if (i > t++) return false;
            }
        }
        t = 0;
        for (int i = 0; i < end.size(); i += 1) {
            if (end[i] == 'L') {
                while (start[t] != 'L') t++;
                if (i > t++) return false;
            }
        }
        return true;
    }
};
