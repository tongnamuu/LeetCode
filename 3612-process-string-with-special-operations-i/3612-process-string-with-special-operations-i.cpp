class Solution {
public:
    string processStr(string s) {
        string ans ="";
        for(char c : s) {
            if(c>='a' && c<='z') {
                ans += c;
            } else if(c=='#') {
                ans = ans + ans;
            }  else if(c=='%') {
                reverse(ans.begin(), ans.end());
            } else if(c=='*') {
                if(ans.empty()) continue;
                ans.pop_back();
            }
        }
        return ans;
    }
};