class Solution {
public:
    int d[100001][2];
    int solve(const string& s, int idx, bool one) {
        if(idx==s.length()) return 0;
        int& ret = d[idx][one];
        if(ret!=-1) return ret;
        if(one) {
            ret = solve(s, idx+1, one) + (s[idx]=='0');
        } else {
            int a = solve(s, idx+1, false) + (s[idx]=='1');
            int b = solve(s, idx+1, true) + (s[idx]=='0');
            ret = min(a, b);
        }
        return ret;
    }
    int minFlipsMonoIncr(string s) {
        memset(d, -1, sizeof(d));
        return solve(s, 0, false);
    }
};
