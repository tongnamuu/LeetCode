class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int>bits(31);
        for(int i=0;i<31;i++) bits[i] = -1;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--) {
            int x = nums[i];
            int idx = i;
            for(int j=0;j<31;j++) {
                if(x&(1<<j)) {
                    bits[j] = i;
                } else {
                    if(bits[j] != -1) {
                        idx = max(idx, bits[j]);
                    }
                }
            }
            ans[i] = idx - i + 1;
        }
        return ans;
    }
};