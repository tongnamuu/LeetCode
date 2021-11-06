class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int idx = 0;
        vector<int>ans;
        while(idx<nums.size()) {
            if(idx+1<nums.size()) {
                if(nums[idx]==nums[idx+1]) idx+= 2;
                else ans.push_back(nums[idx++]); 
            }
            else ans.push_back(nums[idx++]);
        }
        return ans;
    }
};