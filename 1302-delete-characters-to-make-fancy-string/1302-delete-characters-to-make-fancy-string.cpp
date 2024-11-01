class Solution {
public:
    string makeFancyString(string s) {
        string x = "";
        char before = s[0];
        x += before;
        int cnt = 1;
        for(int i=1;i<s.length();i++) {
            if(before==s[i]) {
                cnt++;
                if(cnt<=2) {
                    x += s[i];
                } 
            } else {
                cnt = 1;
                before = s[i];
                x += s[i];
            }
        }
        return x;
    }
};