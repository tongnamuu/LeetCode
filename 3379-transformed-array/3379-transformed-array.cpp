class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++) {
            if (nums[i]>=0) {
                ans[i] = nums[(i+abs(nums[i]))%n];
            } else {
                ans[i] = nums[(n+(i-abs(nums[i]))%n)%n];
            }
        }
        return ans;
    }
};