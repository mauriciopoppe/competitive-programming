class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int i = mid;
            if (mid % 2 == 0) {
                if (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            } else {
                if (i - 1 >= 0 && nums[i - 1] == nums[i]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }
        return nums[lo];
    }
};
