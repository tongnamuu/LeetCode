class Solution {
   public:
    int getNum(char c) {
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        int n = s.length();
        int ans = getNum(s[n - 1]);
        for (int i = 0; i + 1 < n; ++i) {
            int x = getNum(s[i]);
            if (x < getNum(s[i + 1]))
                ans -= x;
            else
                ans += x;
        }
        return ans;
    }
};