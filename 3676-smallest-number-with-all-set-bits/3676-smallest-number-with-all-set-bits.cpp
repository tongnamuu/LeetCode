class Solution {
public:
    int smallestNumber(int n) {
        int res = n;
        long long p = 1L;
        while(n>0) {
            if(n&1) {
                p <<= 1;
                n /= 2;
                continue;
            }
            res += p;
            n /= 2;
            p <<= 1;           
        }
        return res;
    }
};