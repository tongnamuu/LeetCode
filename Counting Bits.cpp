class Solution {
   public:
    vector<int> countBits(int num) {
        vector<int> d(num + 1);
        for (int i = 1; i <= num; ++i) {
            d[i] = d[i >> 1] + (i & 1);
        }
        return d;
    }
};