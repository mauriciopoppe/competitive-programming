class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> m;
        m[0] = 1;
        int sum = 0;
        int total = 0;
        for (int i = 0; i < nums.size(); i += 1) {
            sum += nums[i];
            total += m[sum - k];
            m[sum]++;            
        }
        return total;
    }
};
