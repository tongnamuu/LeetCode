class Solution {
public:
    int cnt[100002];
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        for(int i=1;i<=n;i++) {
            string& x = words[i-1];
            bool s = isStartAndEndWithVowel(x);
            cnt[i] = cnt[i-1] + s;
        }
        int m = queries.size();
        vector<int>ans(m);
        for(int i=0;i<m;i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            ans[i] = cnt[r + 1] - cnt[l];
        }
        return ans;
    }
    bool isStartAndEndWithVowel(string& s) {
        return isVowel(s[0]) && isVowel(s.back());
    }
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c=='i' || c=='o' || c=='u';
    }
};