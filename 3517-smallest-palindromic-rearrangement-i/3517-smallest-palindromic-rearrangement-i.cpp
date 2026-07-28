class Solution {
public:
    int count[26];
    string smallestPalindrome(string s) {
        for(char c : s) {
            count[c-'a']++;
        }
        string front= "";
        string center = "";
        for(char c='a';c<='z';c++) {
            int q = count[c-'a'] / 2;
            int r = count[c-'a'] % 2;
            front += string(q, c);
            if(r) center += c;
        }
        string ans = front + center;
        reverse(front.begin(), front.end());
        ans += front;
        return ans;
    }
};