class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;
        int i=1;
        int cnt = 1;
        char c = word[0];
        for(int i=1;i<word.size();i++) {
            if(word[i]==c) {
                cnt++;
            }  else {
                ans += (cnt - 1);
                cnt = 1;
                c = word[i];
            }
        }
        ans += (cnt - 1);
        return ans;
    }
};