class Solution {
   public:
    void make_comb(vector<vector<int>>& ans, vector<int>& now, const vector<int>& nums, int index, int cur, int target) {
        if (cur == target) {
            ans.push_back(now);
            return;
        }
        if (cur > target) return;
        for (int i = index; i < nums.size(); ++i) {
            now.push_back(nums[i]);
            make_comb(ans, now, nums, i, cur + nums[i], target);
            now.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> now;
        make_comb(ans, now, candidates, 0, 0, target);
        return ans;
    }
};