class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int total = 0;
        
        vector<int> f(grid.size() + 1);
        f[0] = 0;
        for (int i = 1; i <= f.size(); i += 1) {
            f[i] = f[i - 1] + i; 
        }
        
        for (int i1 = 0; i1 < grid.size(); i1 += 1) {
            for (int i2 = i1 + 1; i2 < grid.size(); i2 += 1) {
                vector<int> v = grid[i1];
                int n = 0;
                for (int j = 0; j < grid[i1].size(); j += 1) {
                    v[j] += grid[i2][j];
                    if (v[j] == 2) ++n;
                }
                total += f[n - 1];
            }
        }
        return total;
    }
};
