class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOr = 0;
        int ans = 0;
        for(int i=1;i<(1<<n);i++) {
            int val = 0;
            for(int j=0;j<n;j++) {
                if(i&(1<<j)) {
                    val |= nums[j];
                }
            }
            if(val>maxOr) {
                maxOr = val;
                ans = 1;
            } else if (val==maxOr) ans++;
        }
        return ans;
    }
};