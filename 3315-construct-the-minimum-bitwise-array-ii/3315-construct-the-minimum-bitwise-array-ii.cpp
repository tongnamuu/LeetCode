class Solution {
public:
    int find(int x) {
        int r = 1;
        int result = -1;
        while((x&r) != 0) {
            result = x - r;
            r *= 2;
        }
        return result;
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++) {
            ans[i] = find(nums[i]);
        }
        return ans;
    }
};