class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = n;
        for(int i=0;i<n;i++) {
            long long target = (long long)nums[i] * k;
            int up_index = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
            ans = min(ans, i + n - 1 - up_index + 1);
        }
        return ans;
    }
};