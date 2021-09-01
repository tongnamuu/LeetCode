class Solution {
public:
    int solve(int idx, vector<int>& a, vector<int>& d, vector<int>& visit) {
        if(visit[idx]) return 0;
        if(d[idx] > 0) return d[idx];
        d[idx] = 1;
        visit[idx] = 1;
        d[idx] += solve(a[idx], a, d,visit);
        visit[idx] = 0;
        return d[idx];
    }
    int arrayNesting(vector<int>& nums) {
        vector<int>d(nums.size(), -1);
        vector<int>v(nums.size());
        int ans = -10;
        for(int i=0;i<nums.size();++i){
            ans = max(ans, solve(nums[i], nums, d , v));
        }
        return ans;
    }
};
