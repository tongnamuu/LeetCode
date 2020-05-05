class Solution {
   public:
    int firstUniqChar(string s) {
        map<char, int> m;
        for (char c : s) {
            m[c]++;
        }
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            if (m[s[i]] == 1) return i;
        }
        return -1;
    }
};