class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> left;
        map<int, int> right;
        
        int total_max = 0;
        
        for (int i = 0; i < nums.size(); i += 1) {
            if (!left.count(nums[i])) {
                int reach_left = 0;
                if (left.count(nums[i] - 1)) reach_left += left[nums[i] - 1] + 1;
                int reach_right = 0;
                if (right.count(nums[i] + 1)) reach_right += right[nums[i] + 1] + 1;
                int max_reach = reach_left + reach_right;
                left[nums[i]] = reach_left;
                right[nums[i]] = reach_right;
                if (reach_left) right[nums[i] - reach_left] = max_reach;
                if (reach_right) left[nums[i] + reach_right] = max_reach;
                
                if (max_reach + 1 > total_max) {
                    total_max = max_reach + 1;
                }
            }
        }
        return total_max;
    }
};
