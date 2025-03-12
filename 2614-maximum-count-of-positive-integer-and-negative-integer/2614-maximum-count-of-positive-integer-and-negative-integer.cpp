class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int zero = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int zeroup = upper_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int neg = zero;
        int pos = nums.size() - zeroup;
        return max(neg, pos);
        
    }
};