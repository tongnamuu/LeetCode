class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n; ++j) {
                if (j - 1 > i && nums[j] == nums[j - 1]) continue;
                int c = -nums[i] - nums[j];
                int idx = lower_bound(nums.begin() + j + 1, nums.end(), c) - nums.begin();
                if (idx >= j + 1 && idx < n && nums[idx] == c) {
                    vector<int> temp = {nums[i], nums[j], nums[idx]};
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};