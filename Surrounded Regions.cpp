class Solution {
   public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    void go(int x, int y, vector<vector<int>>& check, vector<vector<char>>& a) {
        check[x][y] = 1;
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 0 && nx < a.size() && ny >= 0 && ny < a[0].size() && !check[nx][ny] && a[nx][ny] == 'O')
                go(nx, ny, check, a);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (!n) return;
        int m = board[0].size();
        vector<vector<int>> check(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            if (!check[i][0] && board[i][0] == 'O') go(i, 0, check, board);
            if (!check[i][m - 1] && board[i][m - 1] == 'O') go(i, m - 1, check, board);
        }
        for (int i = 0; i < m; ++i) {
            if (!check[0][i] && board[0][i] == 'O') go(0, i, check, board);
            if (!check[n - 1][i] && board[n - 1][i] == 'O') go(n - 1, i, check, board);
        }
        for (int i = 1; i < n - 1; ++i) {
            for (int j = 1; j < m - 1; ++j) {
                if (!check[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};