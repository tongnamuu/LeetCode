class Solution {
public:
    int words[10005][26];
    int sub[26];
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        cnt1(words1);
        cnt2(words2);
        for(int i=0;i<words1.size();i++) {
            bool good = true;
            for(char c='a';c<='z';c++) {
                if(words[i][c-'a'] < sub[c-'a']) {
                    good =false;
                    break;
                }
            }
            if(good) ans.push_back(words1[i]);
        }
        return ans;
    }
    void cnt1(vector<string>& w) {
        for(int i = 0; i < w.size(); i++) {
            for(char c : w[i]) {
                words[i][c-'a']++;
            }
        }
    }
        void cnt2(vector<string>& w) {
        for(char x='a';x<='z';x++) {
            int cnt = 0;
            for(int i = 0; i < w.size(); i++) {
                int temp = 0;
                for(char c : w[i]) {
                    if(c==x) temp++;
                }
                cnt = max(cnt, temp);
            }
            sub[x-'a']=cnt;

        }
    }
};