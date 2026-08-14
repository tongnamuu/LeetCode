class Solution {
public:
    int d[26][101];
    int maximumLengthSubstring(string s) {
        int n = s.length();
        d[s[0]-'a'][0] = 1;
        for(int i=1;i<n;i++) {
            d[s[i]-'a'][i]++;
            for(int j=0;j<26;j++) {
                d[j][i] += d[j][i-1];
            }
        }
        int ans = 1;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int good = true;
                for(int k=0;k<26;k++) {
                    int cnt = d[k][j] - (i>=1 ? d[k][i-1] : 0);
                    if(cnt>2) {
                        good = false; break;
                    }
                }
                if(good) ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};