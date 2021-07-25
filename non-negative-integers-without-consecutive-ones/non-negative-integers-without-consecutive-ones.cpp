class Solution {
public:
    long long f[31];
    int findIntegers(int n) {
        f[0] = 1;
        f[1] = 2;
        f[2] = 3;
        for(int i=3;i<=30;++i) {
            f[i] = f[i-1] + f[i-2];
        }
        int ans = 0;
        int k = 30;
        int prev = 0;
        while(k>=0) {
            if(n&(1<<k)) {
                ans += f[k];
                if(prev) return ans;
                prev = 1;
            } else {
                prev = 0;
            }
            --k;
        }
        return ans + 1;
    }
};