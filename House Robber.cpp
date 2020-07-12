class Solution {
   public:
    int solve(int idx, vector<int>& nums, vector<int>& d) {
        if (idx >= nums.size()) return 0;
        if (d[idx] != -1) return d[idx];
        d[idx] = nums[idx];
        for (int i = idx + 2; i < nums.size(); ++i) {
            d[idx] = max(d[idx], nums[idx] + solve(i, nums, d));
        }
        return d[idx];
    }
    int rob(vector<int>& nums) {
        vector<int> d(nums.size(), -1);
        return max(solve(0, nums, d), solve(1, nums, d));
    }
};