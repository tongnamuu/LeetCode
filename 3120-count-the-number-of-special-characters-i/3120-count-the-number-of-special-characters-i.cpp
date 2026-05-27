class Solution {
public:
    int x[26];
    int numberOfSpecialChars(string word) {
        for(char c : word) {
            if(c>='a' && c<='z') {
                x[c-'a'] |= (1<<0);
            } else if(c>='A' && c<='Z') {
                x[c-'A'] |= (1<<1);
            }
        }
        int ans = 0;
        for(int i=0;i<26;i++) ans += (x[i]==3);
        return ans;
    }
};