class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        int n = word.length();
        int i = 0;
        int r = 1;
        while(i<n) {
            ans += min(8, n-i)*r;
            i+=8;
            r++;
        }
        return ans;
    }
};