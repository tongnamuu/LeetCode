class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        if(nums[0] < k) return -1;
        int ans = nums.size();
        if(nums[0] == k) ans--;
        return ans;
    }
};