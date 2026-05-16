class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = nums[0];
        for(int i : nums) ans = min(ans, i);
        return ans;
    }
};