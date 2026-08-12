class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> count;
        int i = -1;
        int j = -1;
        int ans = 0;
        while(i<n && j<n) {
            if(j+1 <n && count[nums[j+1]]<k) {
                count[nums[j+1]]++;
                j++;
                ans = max(ans, j-i);
            } else {
                if(i+1<n) count[nums[i+1]]--;
                i++;
            }
        }

        return ans;
    }
};