class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i=1;
        int n = nums.size();
        if(nums[i] <= nums[i-1]) {
            return false;
        }
        while(i < n && nums[i]>nums[i-1]) {
            i++;
        }
        if(i==n) return false;
        if(nums[i] > nums[i-1]) {
            return false;
        }
        while(i<n && nums[i] < nums[i-1]) {
            i++;
        }
        if(i==n) return false;
        if (nums[i] <= nums[i-1]) {
            return false;
        }
        while(i < n && nums[i]>nums[i-1]) {
            i++;
        }
        if(i!=n) return false;
        return true;
    }
};