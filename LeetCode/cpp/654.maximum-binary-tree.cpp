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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return getNode(nums, 0, nums.size() - 1);
    }

    TreeNode* getNode(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int index = max_index(nums, left, right);
        TreeNode *root = new TreeNode(nums[index]);
        root->left = getNode(nums, left, index - 1);
        root->right = getNode(nums, index + 1, right);
        return root;
    }

    int max_index(vector<int>&nums, int left, int right) {
        int max_index = left;
        for (int i = left; i <= right; i += 1) {
            if (nums[i] > nums[max_index]) {
                max_index = i;
            }
        }
        return max_index;
    }
};
