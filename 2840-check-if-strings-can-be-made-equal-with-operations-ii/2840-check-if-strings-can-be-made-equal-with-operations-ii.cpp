class Solution {
public:
    int cnt[26][2];
    bool checkStrings(string s1, string s2) {
        int n = s1.length();
        for(int i=0;i<n;i++) {
            if(i&1) {
                cnt[s1[i]-'a'][1]++;
                cnt[s2[i]-'a'][1]--;
            } else {
                cnt[s1[i]-'a'][0]++;
                cnt[s2[i]-'a'][0]--;
            }
        }
        for(int i=0;i<26;i++) {
            if(cnt[i][0]!=0 || cnt[i][1]!=0) return false;
        }
        return true;

    }
};