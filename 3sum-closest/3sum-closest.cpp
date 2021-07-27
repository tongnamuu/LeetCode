class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 2147483647;
        int res = 0;
        for(int i=0;i<n;++i){
            for(int j=i+1;j + 1<n;++j){
                int t = target - nums[i] - nums[j];
                int idx = lower_bound(nums.begin() + j + 1, nums.end(), t) - nums.begin();
                int diff1 = 2147483647;
                int diff2 = 2147483647;
                int sum = 0;
                if(idx<n) {
                    sum = nums[i] + nums[j] + nums[idx];
                    if(abs(sum-target) < ans) {
                        ans = abs(sum-target);
                        res = sum;
                    }
                    if(idx-1>j) {
                        sum = nums[i] + nums[j] + nums[idx - 1];
                        if(abs(sum-target) < ans) {
                        ans = abs(sum-target);
                        res = sum;
                        }
                    }
                } else if(idx==n) {
                    sum = nums[i] + nums[j] + nums[idx - 1];
                    if(abs(sum-target) < ans) {
                        ans = abs(sum-target);
                        res = sum;
                    }
                }
            }
        }
        return res;
    }
};
