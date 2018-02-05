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
    int findBottomLeftValue(TreeNode* root) {
        vector<int> leftMost;
        queue<pair<TreeNode*, int>> items;
        items.push({ root, 1 });
        while (!items.empty()) {
            pair<TreeNode*, int> t = items.front();
            items.pop();
            if (t.first == nullptr) {
                continue;
            }
            if (leftMost.size() < t.second) {
                leftMost.push_back(t.first->val);
            }
            items.push({ t.first->left, t.second + 1 });
            items.push({ t.first->right, t.second + 1 });
        }
        return leftMost[leftMost.size() - 1];
    }
};
