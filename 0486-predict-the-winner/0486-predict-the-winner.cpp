class Solution {
public:
    int solve(int left, int right, vector<int>& nums, vector<vector<int>>& d) {
        if(d[left][right]!=-1) return d[left][right];
        if(left==right) return nums[left];
        return d[left][right] = max(nums[left] - solve(left+1, right, nums, d), nums[right] - solve(left, right-1, nums, d));
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> d(n, vector<int>(n, -1));
        int score = solve(0, n-1, nums, d);
        return score >= 0;
    }
};