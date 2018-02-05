/*
 * strategy: while traversing the tree keep track of the ancestors which
 * are lte or gt than the current node, at each step fix their links
 * time-complexity: O(log n)
 * space-complexity: O(log n) (stack size)
 * tags: [binary-tree, bst]
 */
class State {
public:
    TreeNode *lte, *gt;
    State() {
        lte = gt = nullptr;
    }
};

class Solution {
public:
    void trav(TreeNode *root, State *par, State *roots, int V) {
        if (par->lte) par->lte->right = root;
        if (par->gt) par->gt->left = root;
        if (!root) return;

        if (root->val > V) {
            if (!roots->gt) roots->gt = root;
            par->gt = root;
            trav(root->left, par, roots, V);
        } else {
            if (!roots->lte) roots->lte = root;
            par->lte = root;
            trav(root->right, par, roots, V);
        }
    }

    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        State *par = new State();
        State *roots = new State();
        trav(root, par, roots, V);
        vector<TreeNode*> sol = {roots->lte, roots->gt};
        return sol;
    }
};
