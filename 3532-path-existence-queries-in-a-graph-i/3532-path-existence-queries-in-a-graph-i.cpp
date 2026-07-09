class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>parent(n);
        parent[0] = 0;
        for(int i=1;i<n;i++) {
            if(nums[i]-nums[i-1] <= maxDiff) {
                parent[i] = parent[i-1];
            } else {
                parent[i] = i;
            }
        }
        int q = queries.size();
        vector<bool>ans(q);
        for(int i=0;i<q;i++) {
            int x = queries[i][0];
            int y = queries[i][1];
            ans[i] = (parent[x]==parent[y]);
        }
        return ans;
    }
};