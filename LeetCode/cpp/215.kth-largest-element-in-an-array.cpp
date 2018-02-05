class Solution {
public:
    int partition(vector<int> &nums, int start, int end) {
        int pivot = nums[end];
        int i = start - 1;
        for (int j = start; j < end; j += 1) {
            if (nums[j] <= pivot) {
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[end], nums[++i]);
        return i;
    }
    
    int quicksort(vector<int> &nums, int start, int end, int k) {
        int p = partition(nums, start, end);
        if (p == k) return nums[p];
        if (p > k) return quicksort(nums, start, p - 1, k);
        return quicksort(nums, p + 1, end, k);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = quicksort(nums, 0, nums.size() - 1, nums.size() - k);
        return n;
    }
};
