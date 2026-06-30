class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        int cnt[] = {0,0,0};
        while(i<n&&j<n) {
            cnt[s[j]-'a']++;
            while(cnt[0] && cnt[1] && cnt[2]) {
                ans += (n - j);
                cnt[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return ans;

    }
};