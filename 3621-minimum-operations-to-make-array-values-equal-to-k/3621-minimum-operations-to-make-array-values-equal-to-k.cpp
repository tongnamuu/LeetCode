class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        bool already = true;
        for(int i:nums) {
            if(i!=k) {
                already = false;
                break;
            }
        }
        if(already) return 0;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        if(nums[0] < k) return -1;
        int ans = nums.size();
        if(nums[0] == k) ans--;
        return ans;
    }
};