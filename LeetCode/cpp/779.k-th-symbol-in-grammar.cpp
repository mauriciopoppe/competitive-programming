/*
 * strategy: every level is a mirror of the previous level, find the bit in the
 * previous level recursively
 * time-complexity: O(log n)
 * space-complexity: O(1)
 * tags: [ad-hoc, brute-force]
 */
class Solution {
public:
    int kthGrammar(int N, int K) {
        int neg = 0;
        K--;
        N--;
        while (N) {
            int total = 1 << N;
            int half = total / 2;
            if (K >= half) {
                neg = 1 - neg;
                K -= half;
            }
            N--;
        }
        return neg;
    }
};
