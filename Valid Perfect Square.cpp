class Solution {
   public:
    bool isPerfectSquare(int num) {
        if (num == 0 || num == 1) return true;
        long long s = 1, e = num;
        while (s <= e) {
            long long m = s + e >> 1;
            if (m * m <= num)
                s = m + 1;
            else
                e = m - 1;
        }
        return e * e == num;
    }
};