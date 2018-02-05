class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i += 1) {
            if (nums[i] != 0) nums[j++] = nums[i];
        }
        for (int i = j; i < nums.size(); i += 1) {
            nums[i] = 0;
        }
    }
};
