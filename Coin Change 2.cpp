class Solution {
   public:
    int change(int amount, vector<int>& coins) {
        vector<int> d(amount + 1);
        d[0] = 1;
        for (int j : coins) {
            for (int i = 1; i <= amount; ++i) {
                if (i >= j)
                    d[i] += d[i - j];
            }
        }
        return d[amount];
    }
};