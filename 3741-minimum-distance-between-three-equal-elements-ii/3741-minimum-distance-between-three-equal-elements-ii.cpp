class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>> val;
        int n = nums.size();
        int ans = 2147483647;
        for(int i=0;i<n;i++) {
            val[nums[i]].push_back(i);
            if(val[nums[i]].size() >=3) {
                int m = val[nums[i]].size();
                ans = min(ans, 2*(val[nums[i]][m-1] - val[nums[i]][m-3]));
            }
        }
        if(ans == 2147483647) return -1;
        return ans;
    }
};