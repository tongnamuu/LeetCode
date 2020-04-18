class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> d(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                d[i][j] = 2147483647;
                if (j > 0) {
                    d[i][j] = min(d[i][j], d[i][j - 1] + grid[i][j]);
                }
                if (i > 0) {
                    d[i][j] = min(d[i][j], d[i - 1][j] + grid[i][j]);
                }
                if (d[i][j] == 2147483647) d[i][j] = grid[i][j];
            }
        }
        return d[n - 1][m - 1];
    }
};