class Solution {
public:
    bool contain(string& word, string& pattern) {
        int n = word.size();
        int m = pattern.size();
        for(int i=0;i<n;i++) {
            int cnt = 0;
            for(int j=i;cnt<m;j++,cnt++) {
                if(word[j]!=pattern[cnt]) break;
            }
            if(cnt==m) {
                return true;
            }
        }
        return false;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for(string& p : patterns) {
            if(contain(word, p)) ans++;
        }
        return ans;
    }
};