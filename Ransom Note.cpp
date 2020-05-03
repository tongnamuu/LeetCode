class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> m;
        for (char ch : ransomNote) {
            m[ch]++;
        }
        sort(magazine.begin(), magazine.end());
        for (char ch : ransomNote) {
            int x = upper_bound(magazine.begin(), magazine.end(), ch) - lower_bound(magazine.begin(), magazine.end(), ch);
            if (m[ch] > x) return false;
        }
        return true;
    }
};