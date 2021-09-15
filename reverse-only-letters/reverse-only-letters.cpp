class Solution {
public:
    bool isAlp(char x) {
        if('a'<=x && x <= 'z') return true;
        if('A'<=x && x <= 'Z') return true;
        return false;
    }
    string reverseOnlyLetters(string s) {
        int i=0, j = s.length() - 1;
        while(i<j) {
            if(isAlp(s[i]) && isAlp(s[j])) {
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                i++;
                j--;
            } else {
                while(i<j && !isAlp(s[i])) i++;
                while(i<j && !isAlp(s[j])) j--;
            }
        }
        return s;
    }
};
