class Solution {
public:
    int reverseBits(int n) {
        if(n==0) return 0;
        int v = 0;
        int cnt = 0;
        while(n) {
            v *= 2;
            if(n&1) v+= 1;
            n >>= 1;
            cnt++;
        }
        while(cnt<32) {
            v *= 2;
            cnt++;
        }
        return v;
    }
};