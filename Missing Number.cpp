class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        long long sum = 0;
        int s, e = 0;
        for (int i : nums) sum += i, e = max(e, i), s = min(s, i);
        if (s) return 0;
        long long res = (long long)(e * (e + 1)) / 2;
        return res - sum ? res - sum : e + 1;
    }
};