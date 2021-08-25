class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int long i=0;i*i<=c;++i){
            int target = c - i*i;
            long long s=0, e=c;
            while(s<=e) {
                long long m = s + e >> 1;
                if(m*m == target) {
                    return true;
                }
                if(m*m > target) e = m - 1;
                else s = m + 1;
            }
        }
        return false;
    }
};
