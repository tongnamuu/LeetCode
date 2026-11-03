class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());
        int ans = 0;
        for(int i : nums) {
            ans += (maxElement-i);
        }
        return ans;
    }
};