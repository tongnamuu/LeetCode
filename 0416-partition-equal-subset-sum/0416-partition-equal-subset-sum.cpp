class Solution {
public:
    int d[201][20001];
    bool solve(int idx, int val, vector<int>& nums) {
        if(val == 0) {
            return true;
        }
        if(idx<0) {
            return false;
        }
        if(val < 0) return false;
        if(d[idx][val] != -1) {
            if(d[idx][val]>0) return true;
            return false;
        }
        return d[idx][val] = (solve(idx-1, val, nums) || solve(idx-1, val - nums[idx], nums));

    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size(); 
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i=0;i<n;i++) {
            sum += nums[i];
            for(int j=0;j<=20000;j++) {
                d[i][j] = -1;
            }
        }
        if(sum&1) return false;
        bool ans = solve(n-1, sum/2 ,nums);
        return ans;
    }
};