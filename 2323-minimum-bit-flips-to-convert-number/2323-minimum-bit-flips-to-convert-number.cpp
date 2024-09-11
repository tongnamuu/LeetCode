class Solution {
public:
    int minBitFlips(int start, int goal) {
        int r = start ^ goal;
        int ans = 0;
        while(r>0) {
            ans += (r&1);
            r>>=1;
        }
        return ans;
    }
};