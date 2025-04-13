class Solution {
public:
    const long long MOD = 1000000007L;
    long long pow(long long val, long long e) {
        if(e==0) return 1;
        if(e==1) return val % MOD;
        long long res = 1L;
        long long v = val;
        while(e>0) {
            if(e&1) {
                res *= v;
                res %= MOD;
            }
            e >>= 1;
            v *= v;
            v %= MOD;
        }

        return res;
    }
    int countGoodNumbers(long long n) {
        long long odd = n / 2L;
        long even = n - odd;
        long long x = pow(4L, odd);
        long long y = pow(5L, even);
        long long ans = x*y % MOD;
        return ans;
    }
};