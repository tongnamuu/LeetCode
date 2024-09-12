class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int x = 0;
        for(char c : allowed) {
            x |= (1 << (c-'a')); 
        }
        int ans = 0;
        for(string& w : words) {
            int y = 0;
            for(char c : w) {
                y |= (1<<(c-'a'));
            }
            if ((x|y) == x) {
                ans++;
            }
        }
        return ans;
    }
};