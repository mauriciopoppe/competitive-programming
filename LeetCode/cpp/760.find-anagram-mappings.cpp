class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        map<int, vector<int>> toi;
        for (int i = 0; i < B.size(); i += 1) {
            toi[B[i]].push_back(i);
        }
        vector<int> sol;
        for (int i = 0; i < A.size(); i += 1) {
            int t = toi[A[i]].back();
            toi[A[i]].pop_back();
            sol.push_back(t);
        }
        return sol;
    }
};
