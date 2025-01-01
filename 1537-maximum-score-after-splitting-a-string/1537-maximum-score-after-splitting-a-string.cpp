class Solution {
public:
    int count[501][2];
    int maxScore(string s) {
        int n = s.length();
        for(int i=0;i<n;i++) {
            count[i+1][0] = count[i][0] + (s[i] == '0'); 
            count[i+1][1] = count[i][1] + (s[i] == '1');
        }
        int ans = 0;
        for(int i=0;i<n-1;i++) {
            ans = max(ans, count[i+1][0] + count[n][1] - count[i+1][1]);
        }
        return ans;
    }
};
