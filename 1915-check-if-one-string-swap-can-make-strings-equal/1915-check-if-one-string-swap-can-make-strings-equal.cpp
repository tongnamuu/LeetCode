class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        if (n!=s2.length()) return false;

        int idx1 = -1;
        int idx2 = -1;
        int cnt = 0;
        for(int i=0;i<n;i++) {
            if(s1[i]==s2[i]) continue;
            if(cnt==0) idx1 = i;
            else if(cnt==1) idx2 = i;
            cnt++;
        }
        if(cnt ==0) return true;
        if(cnt!=2) return false;
        if(s1[idx1] == s2[idx2] && s1[idx2] == s2[idx1]) return true;
        return false;
    }
};