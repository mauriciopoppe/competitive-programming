
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        int total = 0;
        vector<bool> visited(N);
        for (int i = 0; i < N; i += 1) {
            if (!visited[i]) {
                ++total;
                queue<int> q;
                q.push(i);
                visited[i] = true;                    
                while (q.size()) {
                    int from = q.front();
                    q.pop();
                    for (int j = 0; j < N; j += 1) {
                        if (M[from][j] && !visited[j]) {
                            visited[j] = true;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return total;
    }
};
