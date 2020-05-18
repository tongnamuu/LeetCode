class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int len = p.length();
        vector<int> ans;
        if (n < len) return ans;
        vector<int> alp(26);
        for (char c : p) {
            alp[c - 'a']++;
        }
        vector<int> d(26);
        for (int i = 0; i < len; ++i) {
            d[s[i] - 'a']++;
        }
        if (d == alp) ans.push_back(0);
        for (int i = len; i < n; ++i) {
            d[s[i - len] - 'a']--;
            d[s[i] - 'a']++;
            if (d == alp) ans.push_back(i - len + 1);
        }
        return ans;
    }
};