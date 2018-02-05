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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;
        TreeNode *root = new TreeNode(preorder[0]);
        auto i = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
        vector<int> in_left(inorder.begin(), inorder.begin() + i);
        vector<int> in_right(inorder.begin() + i + 1, inorder.end());
        vector<int> pre_left(preorder.begin() + 1, preorder.begin() + in_left.size() + 1);
        vector<int> pre_right(preorder.begin() + in_left.size() + 1, preorder.end());
        root->left = buildTree(pre_left, in_left);
        root->right = buildTree(pre_right, in_right);
        return root;
    }
};
