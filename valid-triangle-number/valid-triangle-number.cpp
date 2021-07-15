class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;++i){
            for(int j=i+1;j + 1 < n;++j){
                int sum = nums[i] + nums[j];
                int idx = lower_bound(nums.begin() + j + 1, nums.end(), sum) - nums.begin();
                ans += idx - j - 1;
            }
        }
        return ans;
    }
};
