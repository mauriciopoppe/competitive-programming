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
    int find(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root) return 0;
        int self = root == p || root == q;
        int l = find(root->left, p, q);
        int r = find(root->right, p, q);
        return l + r + self;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        int n_left = find(root->left, p, q);
        int n_right = find(root->right, p, q);
        if (n_left == 2) return lowestCommonAncestor(root->left, p, q);
        else if (n_right == 2) return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
