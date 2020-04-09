class Solution {
   public:
    bool backspaceCompare(string S, string T) {
        int l1 = S.length();
        int l2 = T.length();
        string s1 = "", s2 = "";
        l1--;
        l2--;
        int rest = 0;
        while (l1 >= 0) {
            if (rest) {
                rest--;
                --l1;
                while (l1 >= 0 && S[l1] == '#') {
                    rest++;
                    l1--;
                }
                continue;
            }
            if (S[l1] == '#') {
                rest++;
                l1--;
                while (l1 >= 0 && S[l1] == '#') {
                    rest++;
                    l1--;
                }
                continue;
            } else {
                s1 += S[l1];
                l1--;
            }
        }
        rest = 0;
        while (l2 >= 0) {
            if (rest) {
                rest--;
                --l2;
                while (l2 >= 0 && T[l2] == '#') {
                    rest++;
                    l2--;
                }
                continue;
            }
            if (T[l2] == '#') {
                rest++;
                l2--;
                while (l2 >= 0 && T[l2] == '#') {
                    rest++;
                    l2--;
                }
            } else {
                s2 += T[l2];
                l2--;
            }
        }
        return s1 == s2;
    }
};