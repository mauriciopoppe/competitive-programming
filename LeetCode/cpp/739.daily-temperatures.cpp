class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> sol;
        for (int i = temperatures.size() - 1; i >= 0; i -= 1) {
            while (st.size() && st.top().first <= temperatures[i]) {
                st.pop();
            }
            if (st.size()) sol.push_back(st.top().second - i);
            else sol.push_back(0);
            st.push({ temperatures[i], i });
        }
        reverse(sol.begin(), sol.end());
        return sol;
    }
};
