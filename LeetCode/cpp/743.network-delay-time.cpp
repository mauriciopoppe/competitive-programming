class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int, int>>> graph(N + 1, vector<pair<int, int>>());
        for (auto t: times) {
            int from = t[0];
            int to = t[1];
            int w = t[2];
            graph[from].push_back({ to, w });
        }
        int INF = 1<<30;
        vector<int> dp(N + 1, INF);
        set<pair<int, int>> st;
        st.insert({ 0, K });
        dp[K] = 0;        
        while (st.size()) {
            auto top = st.begin();
            int from = top->second;
            st.erase(st.begin());
            for (auto it: graph[from]) {
                int to = it.first;
                int w = it.second;
                if (dp[from] + w < dp[to]) {
                    st.erase({ dp[to], to });
                    dp[to] = dp[from] + w;
                    st.insert({ dp[to], to });
                }
            }
        }
        int total = 0;
        for (int i = 1; i <= N; i += 1) {
            if (dp[i] == INF) return -1;
            total = max(dp[i], total);
        }
        return total;
    }
};
