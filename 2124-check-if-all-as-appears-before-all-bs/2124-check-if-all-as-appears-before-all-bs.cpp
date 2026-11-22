class Solution {
public:
    bool checkString(string s) {
        int idxa = -1;
        int idxb = -1;
        int n = s.length();
        for(int i=0;i<n;i++) {
            char c = s[i];
            if(c=='a') {
                idxa = i;
            } else if(c=='b' && idxb==-1) {
                idxb = i;
            }
        }
        if(idxa==-1||idxb==-1) return true;
        return idxa < idxb;
    }
};