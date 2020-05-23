class Solution {
   public:
    string frequencySort(string s) {
        map<char, int> d;
        for (char c : s) {
            d[c]++;
        }
        sort(s.begin(), s.end(), [&d](const char a, const char b) {
            return d[a] == d[b] ? a > b : d[a] > d[b];
        });
        return s;
    }
};