/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void trav(TreeNode *root, vector<vector<int>> &graph, vector<int> &ch) {
        if (!root) return;
        if (root->left) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }
        if (root->right) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val); 
        }
        ch[root->val] = (root->left != nullptr) + (root->right != nullptr);
        trav(root->left, graph, ch);
        trav(root->right, graph, ch);
    }
    
    int findClosestLeaf(TreeNode* root, int k) {
        vector<vector<int>> graph(1001, vector<int>());
        vector<int> ch(1001, 0);
        trav(root, graph, ch);
        
        int INF = 1e9;
        vector<int> dp(1001, INF);
        queue<int> q;
        dp[k] = 0;
        q.push(k);
        while (q.size()) {
            int from = q.front();
            q.pop();
            for (auto to: graph[from]) {
                if (dp[to] == INF) {
                    printf("from %d to %d\n", from, to);
                    dp[to] = dp[from] + 1;
                    q.push(to);                
                }
            }
        }
        int mn = INF;
        int in = -1;
        for (int i = 1; i < 1001; i += 1) {
            if (dp[i] != INF)
            printf("%d) %d %d\n", i, dp[i], ch[i]);
            if (ch[i] == 0 && dp[i] < mn) {
                in = i;
                mn = dp[i];
            }
        }
        return in;
    }
};
