class Solution {
public:
    int reachNumber(int target) {
        int steps = 0;
        int n = 0;
        for (int i = 1; n != target; i += 1) {
            if (target > 0) {
                if (n + i <= target) n += i;
                else n -= i;
            }
            else if (target < 0) {
                if (n - i >= target) n -= i;
                else n += i;
            }
            ++steps;
        }
        return steps;
    }
};
