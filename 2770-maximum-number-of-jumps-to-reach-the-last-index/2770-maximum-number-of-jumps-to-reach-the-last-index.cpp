class Solution {
public:
    int adj[1001][1001];
    int d[1001];
    int maximumJumps(vector<int>& nums, int target) {

        int n = nums.size();
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(-target<=nums[j]-nums[i] && nums[j]-nums[i]<=target) {
                    adj[i][j] = 1;
                }
            }
        }
        for(int k=0;k<n;k++) {
            for(int i=0;i<n;i++) {
                if(adj[i][k]==0) continue;
                for(int j=i+1;j<n;j++) {
                    if(adj[k][j]==0) continue;
                    if(adj[i][k] + adj[k][j] > adj[i][j]) {
                        adj[i][j] = adj[i][k] + adj[k][j];
                    }
                }
            }
        }
        if(adj[0][n-1]==0) return -1;
        return adj[0][n-1];
    }
};