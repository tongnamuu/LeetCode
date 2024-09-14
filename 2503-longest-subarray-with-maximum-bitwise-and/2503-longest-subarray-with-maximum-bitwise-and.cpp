class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int biggest = nums[0];
        for(int i:nums) {
            if(i > biggest) {
                biggest = i;
            }
        }
        int ans = 0;
        int len = 0;
        for(int i:nums) {
            if((i&biggest) == biggest) {
                len++;
                ans = max(ans, len);
            } else {
                len = 0;
            }
        }
        return ans;
    }
};