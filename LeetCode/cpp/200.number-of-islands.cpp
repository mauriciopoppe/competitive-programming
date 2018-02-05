class Solution {
public:
    bool valid(vector<vector<char>> &grid, int i, int j) {
        return i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size();
    }
    
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int i, int j) {
        visited[i][j] = true;
        vector<int> dx = {0, -1, 0, 1};
        vector<int> dy = {1, 0, -1, 0};
        for (int k = 0; k < 4; k += 1) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (valid(grid, nx, ny) && grid[nx][ny] == '1' && !visited[nx][ny]) {
                dfs(grid, visited, nx, ny);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (!grid.size()) return 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        int total = 0;
        for (int i = 0; i < grid.size(); i += 1) {
            for (int j = 0; j < grid[0].size(); j += 1) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, visited, i, j);
                    total++;
                }
            }
        }
        return total;
    }
};
