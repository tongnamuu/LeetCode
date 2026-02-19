class Solution {
public:
    int countBinarySubstrings(string s) {
        stack<char> st;
        int ans = 0;
        char prev = ' ';
        int zero = 0;
        int one = 0;
        int changed = 0;
        for(char c:s) {
            if(c!=prev) {
                changed++;
                if(changed>=2) {
                    ans += min(zero, one);
                    if(c=='0') {
                        zero = 0;
                    } else {
                        one = 0;
                    }
                } 
            } 
            if(c=='0') {
                zero++;
            } else {
                one++;
            }
            prev = c;
        }
        ans += min(zero, one);
        return ans;
    }
};