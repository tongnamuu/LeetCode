class Solution {
public:
    int x[26];
    int numberOfSpecialChars(string word) {
        for(char c : word) {
            if(c>='a' && c<='z') {
                if((x[c-'a'] & (1<<1)) != 0) {
                    x[c-'a'] |= (1<<2);
                } 
                x[c-'a'] |= (1<<0);
            } else if(c>='A' && c<='Z') {
                x[c-'A'] |= (1<<1);
            }
        }
        int ans = 0;
        for(int i=0;i<26;i++) {
            if(x[i]&(1<<2)) continue;
            if((x[i]&(1<<1)) == 0) continue;
            if((x[i]&(1<<0)) == 0) continue;
            ans++;
        }
        return ans;
    }
};
