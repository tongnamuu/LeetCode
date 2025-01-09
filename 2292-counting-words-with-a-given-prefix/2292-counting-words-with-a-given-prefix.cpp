class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for(string& w : words) {
            ans += isPrefix(w, pref);
        }
        return ans;
    }
    int isPrefix(string& s, string& p) {
        int n = s.size();
        int m = p.size();
        if(n<m) return 0;
        for(int i=0;i<m;i++) {
            if(s[i]!=p[i]) return 0;
        }
        return 1;
    }
};