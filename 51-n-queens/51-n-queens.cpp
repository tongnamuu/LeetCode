class Solution {
public:
    int rdiag[20]={0,};
    int ldiag[20]={0,};
    int column[20] = {0,};
    void dfs(vector<vector<string>>& ans, vector<string>& map, int row, int n) {
        if(row==n) {
            ans.push_back(map);
            return;
        }
        for(int col=0;col<n;++col) {
            if(column[col]) continue;
            if(rdiag[row + col]) continue;
            if(ldiag[n - row + col]) continue;
            map[row][col] = 'Q';
            rdiag[row+col] = 1;
            ldiag[n-row+col] = 1;
            column[col] = 1;
            dfs(ans, map, row+1, n);
            rdiag[row+col] = 0;
            ldiag[n-row+col] = 0;
            column[col] = 0;
            map[row][col] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> map(n);
        for(int i=0;i<n;++i) {
            map[i] = string(n, '.');
        }
        vector<vector<string>>ans;
        dfs(ans, map, 0, n);
        return ans;
    }
};