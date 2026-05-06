class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();
        vector<vector<char>>ans(m, vector<char>(n, '.'));
        queue<char>q;
        for(int i=0;i<n;i++) {
            int idx = m-1;
            for(int j=m-1;j>=0;j--) {
                if(boxGrid[i][j]=='*') {
                    ans[j][n-1-i] = '*';
                    while(!q.empty() && idx >= 0) {
                        ans[idx][n-1-i] = q.front();
                        q.pop();
                        idx--;
                    }
                    idx = j-1;
                } else if(boxGrid[i][j]=='#') {
                    q.push('#');
                } 
            }
            while(!q.empty() && idx >= 0) {
                ans[idx][n-1-i] = q.front();
                q.pop();
                idx--;
            }
        }
        return ans;
    }
};