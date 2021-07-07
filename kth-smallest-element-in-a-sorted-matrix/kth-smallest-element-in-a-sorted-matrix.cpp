class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>q;
        int n = matrix.size();
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                q.push(-matrix[i][j]);
            }
        }
        int ans = -q.top(); q.pop();
        int cnt = 1;
        while(!q.empty()) {
            if(k==cnt) break;
            ans = -q.top();
            q.pop();
            ++cnt;
        }
        return ans;
    }
};