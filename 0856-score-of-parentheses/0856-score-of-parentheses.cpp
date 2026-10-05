class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        int depth = 0;
        int temp = 0;
        int n =s.length();
        for(int i=0;i<n;i++) {
            if(s[i]=='(') {
                depth++;
                temp = 1;
            } else {
                depth--;
                ans += (temp<<depth);
                temp=0;
            }
        }
        return ans;
    }
};