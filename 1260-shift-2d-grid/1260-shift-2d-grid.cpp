class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>temp(n, vector<int>(m));
        for(int t=0;t<k;t++) {
            for(int j=1;j<m;j++) {
                for(int i=0;i<n;i++) {
                    temp[i][j] = grid[i][j-1];
                }            
            }
            temp[0][0] = grid[n-1][m-1];
            for(int i=1;i<n;i++) {
                temp[i][0] = grid[i-1][m-1];
            }
            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    grid[i][j] = temp[i][j];
                }
            }
        }
        return grid;
    }
};