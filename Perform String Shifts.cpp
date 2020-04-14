class Solution {
   public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int n = s.length();
        int m = shift.size();
        int l = 0, r = 0;
        for (int i = 0; i < m; ++i) {
            if (shift[i][0] == 0)
                l += shift[i][1];
            else
                r += shift[i][1];
        }
        l -= r;
        if (l >= 0) {
            l %= n;
            s = s.substr(l) + s.substr(0, l);
        } else {
            l = -l;
            l %= n;
            s = s.substr(n - l) + s.substr(0, n - l);
        }
        return s;
    }
};