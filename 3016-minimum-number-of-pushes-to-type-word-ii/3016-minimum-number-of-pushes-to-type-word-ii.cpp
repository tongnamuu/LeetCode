class Solution {
public:
    int count[26];
    int minimumPushes(string word) {
        for(char c : word) {
            count[c-'a']++;
        }
        string temp;
        for(char c = 'a';c<='z';c++) temp += c;
        sort(temp.begin(), temp.end(), [&](const char& u, const char& v) {
            if(count[u-'a']==count[v-'a']) return u < v;
            return count[u-'a'] > count[v-'a'];
        });
        cout<<temp<<'\n';
        int score = 1;
        int ans = 0;
        int bucket = 0;
        for(char c : temp) {
            int cnt = count[c-'a'];
            if(cnt==0) break;
            ans += cnt * score;
            bucket++;
            if(bucket==8) {
                bucket = 0;
                score += 1;
            }
        }
        return ans;
    }
};