class Solution {
public:
    int d[500002][5] ={0,};
    int findTheLongestSubstring(string s) {
        int n =s.length();
        
        for(int i=1;i<=n;i++) {
            if(s[i-1]=='a') {
                d[i][0] = d[i-1][0] + 1;
            } else {
                d[i][0] = d[i-1][0];
            }
            if(s[i-1]=='e') {
                d[i][1] = d[i-1][1] + 1;
            } else {
                d[i][1] = d[i-1][1];
            }
            if(s[i-1]=='i') {
                d[i][2] = d[i-1][2] + 1;
            } else {
                d[i][2] = d[i-1][2];
            }
            if(s[i-1]=='o') {
                d[i][3] = d[i-1][3] + 1;
            } else {
                d[i][3] = d[i-1][3];
            }
            if(s[i-1]=='u') {
                d[i][4] = d[i-1][4] + 1;
            } else {
                d[i][4] = d[i-1][4];
            }
        }
        int ans = 0;
        for(int i=1;i<=n;i++) {
            for(int j=n;j>=i;j--) {
                bool ok = true;
                for(int k=0;k<5;k++) {
                    int cnt = d[j][k] - d[i-1][k];
                    if(cnt%2 == 1) {
                        ok = false;
                    }
                }
                if(ok) {
                    ans = max(ans, j-i+1);
                    break;
                }
            } 
        }
        return ans;
        
    }

};