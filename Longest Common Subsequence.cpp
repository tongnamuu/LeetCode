class Solution {
   public:
    int d[1001][1001];
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length();
        int len2 = text2.length();
        for (int i = 0; i < len1; ++i) {
            if (text2[0] == text1[i])
                d[0][i] = 1;
            else if (i)
                d[0][i] = d[0][i - 1];
        }
        for (int i = 0; i < len2; ++i) {
            if (text2[i] == text1[0])
                d[i][0] = 1;
            else if (i)
                d[i][0] = d[i - 1][0];
        }
        for (int i = 1; i < len2; ++i) {
            for (int j = 1; j < len1; ++j) {
                d[i][j] = max({d[i - 1][j], d[i][j - 1], d[i - 1][j - 1] + (text2[i] == text1[j] ? 1 : 0)});
            }
        }
        return d[len2 - 1][len1 - 1];
    }
};