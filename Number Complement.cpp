class Solution {
   public:
    int findComplement(int num) {
        if (num == 0) return 1;
        int i = 0;
        int ans = 0;
        while (num) {
            if (!(num & 1)) ans += (1 << i);
            num >>= 1;
            i++;
        }
        return ans;
    }
};