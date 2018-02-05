class Solution {
public:    
    int is_valid(int n) {
        printf("%d\n", n);
        while (n > 9) {
            int r = n % 10;
            int l = (n % 100 - r) / 10;
            if (l > r) return false;
            n /= 10;
        }
        return true;
    }
    
    int monotoneIncreasingDigits(int N) {
        int mx = 0;
        if (is_valid(N)) mx = N;
        for (long long i = 10; i <= N; i *= 10) {
            int r = N % i;
            if (is_valid(N - r - 1)) mx = max(mx, N - r - 1);
        }
        return mx;
    }
};
