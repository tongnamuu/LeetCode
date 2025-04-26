class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minIdx = -1;
        int maxIdx  = -1;
        int out = -1;
        int n = nums.size();
        long long ans = 0;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] == minK) minIdx = i;
            if (nums[i] == maxK) maxIdx = i;
            if (nums[i] < minK || nums[i] > maxK) out = i;
            if (minIdx != -1 && maxIdx != -1) {
                ans += max(0, min(minIdx, maxIdx) - out);
            }
        }
        return ans;
    }
};