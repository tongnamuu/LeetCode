// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
   public:
    int firstBadVersion(int n) {
        long long s = 1;
        long long e = n;
        while (s <= e) {
            long long m = (s + e) >> 1;
            if (isBadVersion((int)m))
                e = m - 1;
            else
                s = m + 1;
        }
        return s;
    }
};