class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = -2147483648;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                ans = max(ans, (nums[i]-1) * (nums[j]-1));
            }
        }
        return ans;
    }
};