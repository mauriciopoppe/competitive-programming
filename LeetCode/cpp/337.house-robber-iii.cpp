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
    int traverse(TreeNode *root) {
        if (!root) return 0;
        int mx = traverse(root->left) + traverse(root->right);
        mx = max(
            mx,
            root->val +
            (root->left && root->left->left ? traverse(root->left->left) : 0) +
            (root->left && root->left->right ? traverse(root->left->right) : 0) +
            (root->right && root->right->left ? traverse(root->right->left) : 0) +
            (root->right && root->right->right ? traverse(root->right->right) : 0)     
        );
        return mx;
    }
    
    int rob(TreeNode* root) {
        return traverse(root);
    }
};
