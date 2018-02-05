vector<int> dx = {0, -1, 0, 1};
vector<int> dy = {1, 0, -1, 0};
typedef map<pair<int, int>, bool> mii;
mii walls;
        
class Solution {
public:    
    int encode(vector<vector<int>> &grid, int x, int y) {
        return x * grid[0].size() + y;
    }
    
    int isvalid(vector<vector<int>> &grid, int x, int y) {
        return x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size();
    }
    
    int haswall(vector<vector<int>> &grid, int i, int j, int x, int y) {
        int a = encode(grid, i, j);
        int b = encode(grid, x, y);        
        return walls.count({ min(a, b), max(a, b) }) > 0;
    }
    
    void setwall(vector<vector<int>> &grid, int i, int j, int x, int y) {
        int a = encode(grid, i, j);
        int b = encode(grid, x, y);
        // if (a < b)
        //     printf("[%d %d] - [%d %d]\n", i, j, x, y);
        // else 
        //     printf("[%d %d] - [%d %d]\n", x, y, i, j);
        walls[{ min(a, b), max(a, b) }] = true;
    }
    
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, set<pair<int, int>> &total, int x, int y) {
        visited[x][y] = 1;
        for (int i = 0; i < 4; i += 1) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isvalid(grid, nx, ny) && !haswall(grid, x, y, nx, ny) && !visited[nx][ny]) {                
                if (grid[nx][ny] == 0) total.insert({ nx, ny });
                else dfs(grid, visited, total, nx, ny);
            }
        }
    }
    
    void kill(vector<vector<int>> &grid, vector<vector<int>> &visited, int x, int y) {
        visited[x][y] = 1;
        for (int i = 0; i < 4; i += 1) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isvalid(grid, nx, ny) && !haswall(grid, x, y, nx, ny) && !visited[nx][ny]) {
                if (grid[nx][ny]) kill(grid, visited, nx, ny);
                else setwall(grid, x, y, nx, ny);
            }
        }
    }
    
    int containVirus(vector<vector<int>>& grid) {
        int total = 0;
        walls.clear();
        // for (int i = 0; i < grid.size(); i += 1) {
        //          for (int j = 0; j < grid[0].size(); j += 1) {
        //              printf("%d ", grid[i][j]);
        //          }
        //         printf("\n");
        //     }
            
        while (true) {
            vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), false));
            int best = 0;
            pair<int, int> tok;
            
            for (int i = 0; i < grid.size(); i += 1) { 
                for (int j = 0; j < grid[0].size(); j += 1) {
                    if (!visited[i][j] && grid[i][j]) {
                        set<pair<int, int>> s;                        
                        dfs(grid, visited, s, i, j);
                        if (s.size() > best) {
                            tok = {i, j};
                            best = s.size();
                        }
                    }
                }
            }
            
            if (best == 0) break;
            
            // printf("%d\n", best);
            for (auto &row: visited) for (auto &v: row) v = 0;
            kill(grid, visited, tok.first, tok.second);
            // printf("kill size %d\n", walls.size());
            vector<vector<int>> clone = grid;
            for (int i = 0; i < grid.size(); i += 1) {
                for (int j = 0; j < grid[0].size(); j += 1) {
                    if (grid[i][j]) {
                        for (int k = 0; k < 4; k += 1) {
                            int nx = i + dx[k];
                            int ny = j + dy[k];
                            if (isvalid(grid, nx, ny) && !haswall(grid, i, j, nx, ny)) {
                                clone[nx][ny] = 1;                                
                            }
                        }
                    }
                }
            }
            grid = clone;
            // for (int i = 0; i < grid.size(); i += 1) {
            //      for (int j = 0; j < grid[0].size(); j += 1) {
            //          printf("%d ", clone[i][j]);
            //      }
            //     printf("\n");
            // }
            total += best;            
        }
        return walls.size();
    }
};
