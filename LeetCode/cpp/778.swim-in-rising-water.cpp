/*
 * strategy: if we try all possible t between 0 and N * N (through dfs) and
 * store them in an array it looks like [false, false, false, true, true], so
 * the invariant is that from some i it's always possible to connect both
 * points, to find the first true we can use binary search
 * time-complexity: O(n^2 log m) m = n*n, n is the size of the diagonal
 * space-complexity: O(m), m = n * n
 * tags: [dfs, binary-search]
 */
class Solution {
public:
    int N;
    vector<vector<bool>> visited;

    void dfs(vector<vector<int>> &grid, int t, int x, int y) {
        if (visited[x][y]) return;
        if (grid[x][y] > t) return;
        visited[x][y] = true;
        if (x + 1 < N) dfs(grid, t, x + 1, y);
        if (y + 1 < N) dfs(grid, t, x, y + 1);
        if (x - 1 >= 0) dfs(grid, t, x - 1, y);
        if (y - 1 >= 0) dfs(grid, t, x, y - 1);
    }

    bool solve(vector<vector<int>> &grid, int t) {
        visited = vector<vector<bool>>(N, vector<bool>(N));
        dfs(grid, t, 0, 0);
        return visited[N - 1][N - 1];
    }

    int swimInWater(vector<vector<int>>& grid) {
        N = grid.size();
        int lo = 0;
        int hi = N * N;
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if (solve(grid, mid)) hi = mid;
            else lo = mid;
        }
        return hi;
    }
};
