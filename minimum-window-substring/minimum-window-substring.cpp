class Solution {
public:
    int cnt[52][2];
    bool ok() {
        for(int i=0;i<52;++i) {
            if(cnt[i][0] < cnt[i][1]) return false;
        }
        return true;
    }
    int convert(char c) {
        if(c>='a' && c <= 'z') return c - 'a';
        return c -'A' + 26;
    }
    string minWindow(string s, string t) {
        for(char c : t) {
            int x = convert(c);
            cnt[x][1]++;
        }
        int i = 0, j = 0;
        cnt[convert(s[i])][0]++;
        int n = s.length();
        int ans = 2147483647;
        int sidx = 0;
        while(i<n && j< n) {
            if(ok()) {
                if(ans > j - i + 1) {
                    ans = j - i + 1;
                    sidx = i;
                }
                cnt[convert(s[i])][0]--;
                i++;
            } else {
                j++;
                if(j<n) cnt[convert(s[j])][0]++;
            }
        }
        if(ans==2147483647) return "";
        return s.substr(sidx, ans);
    }
};
