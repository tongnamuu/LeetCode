class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int total = 0;
        for(int i : nums) total += i;
        int n = nums.size();
        vector<int>ans(n);
        int l = 0;
        for(int i=0;i<n;i++) {
            int r = total - l;
            l += nums[i];
            ans[i] = abs(r-l);
        }
        return ans;
    }
};