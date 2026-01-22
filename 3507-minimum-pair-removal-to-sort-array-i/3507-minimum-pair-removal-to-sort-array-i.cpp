class Solution {
public:
    bool increasing(vector<int>& nums) {
        bool increasing = true;
        for(int i=1;i<nums.size();i++) {
            if (nums[i] < nums[i-1]) {
                return false;
            }
        }
        return true;
    }
    void replace(vector<int>& nums) {
        if (nums.size() <=1) return;
        int temp = nums[0] + nums[1];
        int idx = 0;
        for(int i=0;i<nums.size()-1;i++) {
            if (nums[i] + nums[i+1] < temp) {
                temp = nums[i] + nums[i+1];
                idx = i;
            }
        }
        vector<int>result;
        for(int i=0;i<idx;i++) {
            result.push_back(nums[i]);
        }
        result.push_back(temp);
        for(int i=idx+2;i<nums.size();i++) {
            result.push_back(nums[i]);
        }
        nums = result;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;
        while(true) {
            bool increased = increasing(nums);
            if (increased) return ans;
            replace(nums);
            ans++;
        }
        return ans;
    }
};