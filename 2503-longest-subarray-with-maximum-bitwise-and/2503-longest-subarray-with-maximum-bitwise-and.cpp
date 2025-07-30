class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxv = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        int cur = nums[0];
        int temp = 0;
        int ans = 0;
        for(int i=0;i<n;i++) {
            if(nums[i]==maxv) {
                temp += 1;
                ans = max(ans, temp);
            } else {
                temp = 0;
            }
        }
        return ans;
    }
};