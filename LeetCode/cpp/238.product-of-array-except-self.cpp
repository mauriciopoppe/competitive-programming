class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> sol(nums.size(), 1);
        for (int i = 0; i < nums.size(); i += 1) {
            sol[i] *= nums[i];
            if (i) sol[i] *= sol[i - 1];
        }
        int p = 1;
        for (int i = nums.size() - 1; i >= 0; i -= 1) {
            int left = i - 1 >= 0 ? sol[i - 1] : 1;
            int right = p;
            sol[i] = left * right;
            p *= nums[i];
        }
        return sol;
    }
};
