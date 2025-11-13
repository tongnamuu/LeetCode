class Solution {
public:
    int maxOperations(string s) {
        bool one_find = false;
        int cnt = 0;
        int ans = 0;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='0') {
                if(one_find) {
                    ans += cnt;
                    one_find = false;
                }
            } else if (s[i]=='1') {
                one_find = true;
                cnt += 1;
            }
        }
        return ans;
    }
};