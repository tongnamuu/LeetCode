class Solution {
   public:
    int numSquares(int n) {
        vector<int> d(n + 1);
        for (int i = 1; i <= n; ++i) {
            d[i] = n;
            for (int k = 1; k * k <= i; ++k) {
                d[i] = min(d[i - k * k] + 1, d[i]);
            }
        }
        return d[n];
    }
};