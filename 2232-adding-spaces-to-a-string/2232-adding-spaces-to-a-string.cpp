class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string x = "";
        int i = 0;
        int j = 0;
        while(i<s.length() && j < spaces.size()) {
            if (i==spaces[j]) {
                x += ' ';
                j++;
            }
            x += s[i];
            i++;
        }
        while (i<s.length()) {
            x += s[i];
            i++;
        }
        return x;
    }
};