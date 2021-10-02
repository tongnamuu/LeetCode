class Solution {
public:
    int d[1002][1002];
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        int ans = 0;
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                if(text1[i]==text2[j]) {
                     d[i+1][j+1] = max({ d[i+1][j], d[i+1][j], d[i][j] + 1 });
                } else {
                    d[i+1][j+1] = max({ d[i][j+1], d[i+1][j] });
                }
                ans =  max(ans,d[i+1][j+1]);
            }
        }

        return ans;
    }
};