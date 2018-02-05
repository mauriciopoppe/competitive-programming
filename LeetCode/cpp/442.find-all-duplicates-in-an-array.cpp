class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i += 1) {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0) res.push_back(index + 1);
            nums[index] *= -1;
        }
        return res;
    }
};
