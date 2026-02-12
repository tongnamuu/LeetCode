class Solution {
public:
    int cnt[26];
    int longestBalanced(string s) {
        int n = s.length();
        int ans = 1;
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                cnt[s[j]-'a']++;
                int temp = cnt[s[i]-'a'];
                bool good = true;
                for(int k=0;k<26;k++) {
                    if (cnt[k]==0) continue;
                    if (cnt[k]!=temp) {
                        good = false;
                        break;
                    }
                }
                if (good) {
                    ans = max(ans, j-i+1);                  
                }
            }
            for(int j=i;j<n;j++) {
                cnt[s[j]-'a']--;
            }
        }
        return ans;
    }
};