class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int len = s2.length();
        if (n > len) return false;
        vector<int> d1(26);
        vector<int> d2(26);
        for (int i = 0; i < n; ++i) {
            d1[s1[i] - 'a']++;
            d2[s2[i] - 'a']++;
        }
        if (d1 == d2) return true;
        for (int i = n; i < len; ++i) {
            d2[s2[i - n] - 'a']--;
            d2[s2[i] - 'a']++;
            if (d2 == d1) return true;
        }
        return false;
    }
};