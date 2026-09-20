class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for(int i=0;i<s.length();i++) {
            int idx = i + 1;
            int cur = s[i] - 'a' + 1;
            int rev = 27 - cur;
            ans += idx*rev;
        }
        return ans;
    }
};