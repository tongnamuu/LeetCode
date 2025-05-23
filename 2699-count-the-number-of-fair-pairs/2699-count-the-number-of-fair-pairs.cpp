class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = 0;
        for(int i=0;i<n;i++) {
            int minV = lower - nums[i];
            int maxV = upper - nums[i];
            int minIdx = lower_bound(nums.begin() + i + 1, nums.end(), minV) - (nums.begin());
            int maxIdx = upper_bound(nums.begin() + i + 1, nums.end(), maxV) - (nums.begin());
            // minIdx
            if(minIdx>=n) continue;
            //maxIdx
            maxIdx -= 1;
            if (minIdx<n && maxIdx < n && minIdx<=maxIdx) {
                ans += (long long)(maxIdx - minIdx + 1);
            }
            
        }

        return ans;
    }
};