class Solution {
   public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const int dx[4] = {0, 0, -1, 1};
        const int dy[4] = {-1, 1, 0, 0};
        int n = grid.size();
        if (!n) return 0;
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) continue;
                int cnt = 4;
                for (int dir = 0; dir < 4; ++dir) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                        if (grid[nx][ny] == 1) {
                            cnt--;
                        }
                    }
                }
                ans += cnt;
            }
        }
        return ans;
    }
};