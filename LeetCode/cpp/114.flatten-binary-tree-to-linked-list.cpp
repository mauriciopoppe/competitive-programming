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
    TreeNode* flatten_rec(TreeNode *root) {
        if (!root) return nullptr;
        TreeNode *r = flatten_rec(root->right);
        TreeNode *l = flatten_rec(root->left);
        if (l) {
            root->right = l;
            TreeNode *it = l;
            while (it->right) it = it->right;
            it->right = r;
            root->left = nullptr;
        }
        return root;
    }
    
    void flatten(TreeNode* root) {
        flatten_rec(root);
    }
};
