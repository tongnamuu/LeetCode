class Solution {
   public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> d(m + 1, vector<int>(n + 1));
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[j - 1] == t[i - 1]) {
                    d[i][j] = d[i - 1][j - 1] + 1;
                } else
                    d[i][j] = max(d[i - 1][j], d[i][j - 1]);
                ans = max(d[i][j], ans);
            }
        }
        return ans == n;
    }
};