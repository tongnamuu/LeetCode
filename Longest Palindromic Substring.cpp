class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.length();
        int ans = 1;
        int idx = 0;
        vector<vector<int>> d(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            d[i][i] = 1;
            if (i + 1 < n && s[i] == s[i + 1]) {
                d[i][i + 1] = 1;
                idx = i;
                ans = 2;
            }
        }
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i < n; ++i) {
                int j = len + i - 1;
                if (j >= n) break;
                if (s[i] == s[j] && d[i + 1][j - 1]) {
                    d[i][j] = 1;
                    if (ans < len) {
                        ans = len;
                        idx = i;
                    }
                }
            }
        }
        return s.substr(idx, ans);
    }
};