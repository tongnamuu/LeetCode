class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (!n) return 0;
        int m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> d(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    d[i][j] = min({d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]}) + 1;
                    ans = max(d[i][j], ans);
                }
            }
        }
        return ans * ans;
    }
};