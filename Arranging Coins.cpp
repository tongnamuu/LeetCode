class Solution {
   public:
    int arrangeCoins(int n) {
        int s = 0, e = 2147483647;
        while (s <= e) {
            long long m = (long long)(s + e) >> 1;
            if (m * (m + 1) / 2 > n)
                e = m - 1;
            else
                s = m + 1;
        }
        return e;
    }
};