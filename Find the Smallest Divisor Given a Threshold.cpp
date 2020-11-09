class Solution {
   public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s = 1;
        int e = 1000000;
        while (s <= e) {
            int m = s + e >> 1;
            int val = 0;
            for (int k : nums) {
                int x = ceil((double)k / m);
                val += x;
            }
            if (val > threshold) {
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        return s;
    }
};
