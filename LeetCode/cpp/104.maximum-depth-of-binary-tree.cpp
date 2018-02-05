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
    int trav(TreeNode *root) {
        if (!root) return 0;
        return max(trav(root->left), trav(root->right)) + 1;
    }
    
    int maxDepth(TreeNode* root) {
        return trav(root);
    }
};
