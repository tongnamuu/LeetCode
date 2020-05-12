class Solution {
   public:
    const int dx[4] = {0, 0, -1, 1};
    const int dy[4] = {-1, 1, 0, 0};
    void go(vector<vector<bool>>& check, vector<vector<int>>& a, int x, int y, int color, int newColor) {
        check[x][y] = true;
        a[x][y] = newColor;
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 0 && nx < check.size() && ny >= 0 && ny < check[0].size() && a[nx][ny] == color && !check[nx][ny]) {
                go(check, a, nx, ny, color, newColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        vector<vector<bool>> check(image.size(), vector<bool>(image[0].size()));
        go(check, image, sr, sc, color, newColor);
        return image;
    }
};