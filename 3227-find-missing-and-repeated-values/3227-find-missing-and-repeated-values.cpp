class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>ans(2);
        int sum = 0;
        vector<int>cnt(2501);
        for(vector<int>& a : grid) {
            for(int j : a) {
                if(cnt[j]) {
                    ans[0] = j;
                } else {
                    cnt[j]++;
                    sum += j;
                }
            }
        }
        int max_value = grid.size() * grid.size();
        ans[1] = max_value*(max_value+1)/2 - sum;
        return ans;
    }
};