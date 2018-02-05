class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int lo = 1;
        int hi = nums.size() - 1;
        int best = -1;
        while (lo <= hi) {
            // 1 2 3 4 2
            // pred(how many less than n)
            // pred(1) = 0
            // pred(2) = 1
            // pred(3) = 3
            // pred(4) = 4
            
            // 1 1
            // pred(1) = 0
            // pred(2) = 2
            
            // 7 9 7 4 2 8 7 7 1 5
            // 1: 0
            // 2: 1
            // 3: 2
            // 4: 2
            // 5: 3
            // 6: 4
            // 7: 4
            // 8: 8
            
            int mid = lo + (hi - lo) / 2;
            int cnt = 0;
            int eq = 0;
            for (int i = 0; i < nums.size(); i += 1) {
                if (nums[i] < mid) ++cnt;
                if (mid == nums[i]) ++eq;
            }
            if (eq > 1) return mid;
            if (cnt < mid) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return best;
    }
};
