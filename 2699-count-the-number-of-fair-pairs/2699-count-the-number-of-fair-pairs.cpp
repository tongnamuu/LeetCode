class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = 0;
        for(int i:nums) cout<<i<<' ';
        cout<<'\n';
        for(int i=0;i<n;i++) {
            int minV = lower - nums[i];
            int maxV = upper - nums[i];
            int minIdx = lower_bound(nums.begin() + i + 1, nums.end(), minV) - (nums.begin() + i + 1);
            int maxIdx = upper_bound(nums.begin() + i + 1, nums.end(), maxV) - (nums.begin() + i + 1);
            // minIdx
            if(minIdx>=n) continue;
            //maxIdx
            maxIdx -= 1;
            if (minIdx<n && maxIdx < n && minIdx<=maxIdx) {
                ans += (long long)(maxIdx - minIdx + 1);
                cout<<i<<' '<<minIdx<<' '<<maxIdx<<'\n';
            }
            
        }

        return ans;
    }
};