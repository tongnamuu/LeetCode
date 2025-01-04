class Solution {
public:
    int countSubsequence(string& s, char c) {
        int n = s.length();
        int idx1 = -1;
        int idx2 = -1;
        for(int i=0;i<n;i++) {
            if (s[i] == c) {
                idx1 = i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--) {
            if (s[i] == c) {
                idx2 = i;
                break;
            }
        }
        if(idx1==-1||idx2==-1||idx1==idx2) return 0;
        int x = 0;
        for(int i=idx1+1;i<idx2;i++) {
            x |= (1<<(s[i]-'a'));
        }
        int cnt = 0;
        while(x) {
            if (x & 1) cnt++;
            x >>= 1;
        }
        return cnt;
    }
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        for(char c = 'a';c <='z';c++) {
            ans += countSubsequence(s, c);
        }
        return ans;
    }
};