class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000) return 0L;
        long long temp = n;
        int len = 0;
        while(temp>0) {
            len++;
            temp/=10L;
        }
        long long ans = 0L;
        long long tens = 10L;
        long long commas = 1L;
        int r = 0;
        //0~9
        //10~99 // 100 - 10
        // 100-999// 1000-100
        // 1000-9999 // 10000-1000
        for(int i=1;i<len;i++) {
            long long cnt = tens -tens/10;
            if(tens>=10000) {
                ans += cnt * commas;
                r++;
                if(r>=3) {
                    commas++;
                    r = 0;
                }
            }
            tens *= 10;
        }
        long long cnt = n - tens/10 + 1;
        ans += cnt * commas;
        return ans;
    }
};