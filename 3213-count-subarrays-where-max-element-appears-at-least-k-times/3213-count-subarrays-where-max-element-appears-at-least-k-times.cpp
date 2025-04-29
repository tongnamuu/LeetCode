class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int target = *max_element(nums.begin(), nums.end());
        int i = 0;
        int j = 0;
        int n = nums.size();
        int cnt = 0;
        while(i<n && j<n) {
            if(nums[j]==target) {
                cnt++;
            }
            while(i<=j && cnt>=k) {
                ans += n-1-j+1;
                if(nums[i]==target) cnt--;
                i++;
            }
            j++;
        }
        return ans;
    }
};