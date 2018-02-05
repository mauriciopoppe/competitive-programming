class Solution {
public:
    int maxsquare(vector<int> &v) {
        int mx = 0;
        v.push_back(0);
        stack<int> pos;
        for (int i = 0; i < v.size(); i += 1) {
            while (pos.size() && v[pos.top()] >= v[i]) {
                int h = v[pos.top()];
                pos.pop();
                int l = pos.size() ? pos.top() : -1;
                int square = min(h, i - l - 1);
                mx = max(mx, square * square);
            }
            pos.push(i);
        }
        v.pop_back();
        return mx;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        if (!matrix.size()) return 0;
        vector<int> v(matrix[0].size(), 0);
        int mx = 0;
        for (int i = 0; i < matrix.size(); i += 1) {
            for (int j = 0; j < matrix[0].size(); j += 1) {
                if (matrix[i][j] == '1') v[j] += 1;
                else v[j] = 0;
            }
            mx = max(mx, maxsquare(v));
        }
        return mx;
    }
};
