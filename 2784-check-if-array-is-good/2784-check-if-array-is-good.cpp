class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int target = 1;
        int n = nums.size();
        if(n==1) return false;
        for(int i=0;i<n-2;i++) {
            if(nums[i]!=target) return false;
            target++;
        }
        if(nums[n-2]!=target) return false;
        if(nums[n-1]!=target) return false;
        return true;
    }
};