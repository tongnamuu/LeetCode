class Solution {
   public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        int r = x ^ y;
        while (r) {
            if (r & 1) ans++;
            r >>= 1;
        }
        return ans;
    }
};