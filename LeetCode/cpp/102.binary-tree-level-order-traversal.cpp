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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> sol;
        queue<pair<TreeNode*, int>> q;
        if (root) q.push({ root, 0 });
        while (q.size()) {
            pair<TreeNode*, int> top = q.front();
            TreeNode *it = top.first;
            int level = top.second;
            q.pop();
            if (level + 1 > sol.size()) {
                sol.push_back(vector<int>());
            }
            sol[level].push_back(it->val);
            if (it->left) q.push({ it->left, level + 1});
            if (it->right) q.push({ it->right, level + 1});
        }
        return sol;
    }
};
