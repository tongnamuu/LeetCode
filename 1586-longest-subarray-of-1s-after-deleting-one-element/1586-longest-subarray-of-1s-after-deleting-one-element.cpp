class Solution {
public:
    int d[100001][2];
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if(nums[0]==1) {
            d[0][0] = 1;
        }
        int ans = 0;
        for(int i=1;i<n;i++) {
            if(nums[i]==0) {
                d[i][1] = d[i-1][0];
            } else {
                d[i][0] = d[i-1][0] + 1;
                d[i][1] = d[i-1][1] + 1;                
            }
            ans = max(d[i][0] - 1, ans);
            ans = max(d[i][1], ans);
            //cout<<d[i][0]<<' '<<d[i][1]<<'\n';
        }
        return ans;
    }
};