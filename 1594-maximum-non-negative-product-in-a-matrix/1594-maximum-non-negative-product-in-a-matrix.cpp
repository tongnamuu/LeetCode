class Solution {
public:
    long long d[16][16][2];
    int maxProductPath(vector<vector<int>>& grid) {
        long long MOD = 1000000007L;
        int n = grid.size();
        int m = grid[0].size();
        d[0][0][0] = d[0][0][1] = grid[0][0];
        for(int i=1;i<n;i++) d[i][0][0] = d[i][0][1] = (d[i-1][0][0] * grid[i][0]) % MOD;
        for(int j=1;j<m;j++) d[0][j][0] = d[0][j][1] = (d[0][j-1][0] * grid[0][j]) % MOD;
        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                if (grid[i][j] >= 0) {
                    long long x1 = d[i][j-1][0];
                    long long y1 = d[i-1][j][0];
                    long long x2 = d[i][j-1][1];
                    long long y2 = d[i-1][j][1];
                    d[i][j][0] = max({x1,y1}) * grid[i][j];
                    d[i][j][1] = min(x2,y2) * grid[i][j];
                } else {
                    long long x1 = d[i][j-1][0];
                    long long y1 = d[i-1][j][0];
                    long long x2 = d[i][j-1][1];
                    long long y2 = d[i-1][j][1];
                    d[i][j][0] = min({x2,y2}) * grid[i][j];
                    d[i][j][1] = max(x1,y1) * grid[i][j];
                }
            }
        }
        long long ans = d[n-1][m-1][0];
        if(ans<0) return -1;
        return ans % MOD;

    }
};