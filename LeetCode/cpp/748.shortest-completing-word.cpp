class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        map<char, int> m;
        for (char c: licensePlate) if (isalpha(c)) m[tolower(c)]++;

        int sol = -1;
        for (int i = 0; i < words.size(); i += 1) {
            map<char, int> m2;
            for (char c: words[i]) if (isalpha(c)) m2[tolower(c)]++;
            bool is_valid = true;
            for (auto it: m) {
                if (m2[it.first] < it.second) {
                    is_valid = false;
                }
            }
            if (is_valid && (sol == -1 || words[sol].size() > words[i].size())) sol = i;
        }
        return words[sol];
    }
};
