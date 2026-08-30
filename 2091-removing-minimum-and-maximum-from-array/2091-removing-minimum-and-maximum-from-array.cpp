class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if(nums.size()<=2) return nums.size();
        int max_idx = 0;
        int min_idx = 0;
        int min_val = nums[0];
        int max_val = nums[0];
        int n = nums.size();
        for(int i=1;i<n;i++) {
            if(min_val > nums[i]) {
                min_val = nums[i];
                min_idx = i;
            }
            if(max_val<nums[i]) {
                max_val = nums[i];
                max_idx = i;
            }
        }
        int ans = max(min_idx+1, max_idx+1);
        ans = min(ans, max(n-min_idx, n-max_idx));
        ans = min(ans, min_idx+1 + n-max_idx);
        ans = min(ans, n-min_idx + max_idx+1);
        return ans;
    }
};