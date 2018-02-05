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
    
    int rec (TreeNode* it, int &mx) {
        if (!it) return 0;
        int l = rec(it->left, mx);
        int r = rec(it->right, mx);
        mx = max(it->val, mx);
        mx = max(l + r + it->val, mx);        
        int best = max(max(l + it->val, r + it->val), 0);
        return best;
    }
    
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        int mx = root->val;
        rec(root, mx);
        return mx;
    }
};
