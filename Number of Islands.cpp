class Solution {
   public:
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};
    void go(int n, int m, int x, int y, vector<vector<bool>>& check, const vector<vector<char>>& a) {
        check[x][y] = true;
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !check[nx][ny] && a[nx][ny] == '1') {
                go(n, m, nx, ny, check, a);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> check(n, vector<bool>(m));
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!check[i][j] && grid[i][j] == '1') {
                    go(n, m, i, j, check, grid);
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};