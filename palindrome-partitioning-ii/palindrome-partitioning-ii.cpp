class Solution {
public:
    int p[2001][2001];
    int d[2001];
    int minCut(string& s) {
        int n = s.length();
        for(int i=0;i<n;++i) {
            p[i][i] = 1;
            if(i+1<n && s[i]==s[i+1]) p[i][i+1] = 1;
        }
        for(int len=3;len<=n;++len) {
            for(int i=0;i<n;++i){
                int j = len + i - 1;
                if(j>=n || j <= i) break;
                p[i][j] = (s[i] == s[j] && p[i+1][j-1]);
            }
        }
        for(int i=0;i<n;++i){
            int val = i;
            for(int j=0;j<=i;++j) {
                if(p[j][i]) {
                    val = j==0? 0 : min(val, d[j-1] + 1);
                }
            }
            d[i] = val;
        }
        return d[n-1];
    }
};
