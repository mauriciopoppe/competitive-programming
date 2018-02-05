class BST {
  public:
    struct Node {
        int v;
        int dup;
        int sum;
        Node *left, *right;
        Node(int _v) {
            v = _v;
            dup = 1;
            sum = 0;
            left = right = nullptr;
        }
    };
    
    Node *root;
    
    BST() {
        root = nullptr;
    }
    
    int insert(int v) {
        return insert(v, root);
    }
    
    int insert(int v, Node *&root) {
        if (!root) {
            root = new Node(v);
            return 0;
        } else if (v == root->v) {
            root->dup++;
            return root->sum;
        } else if (v < root->v) {
            root->sum++;
            return insert(v, root->left);
        } else {            
            return root->sum + root->dup + insert(v, root->right);
        }
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        BST t;
        vector<int> sol;
        for (int i = nums.size() - 1; i >= 0; i -= 1) {
            sol.push_back(t.insert(nums[i]));
        }
        reverse(sol.begin(), sol.end());
        return sol;
    }
};
