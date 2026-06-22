class Solution {
public:
    int cnt[26];
    int maxNumberOfBalloons(string text) {
        for(char c : text) {
            cnt[c-'a']++;
        }
        int bcnt = cnt['b'-'a'];
        int acnt = cnt['a'-'a'];
        int lcnt = cnt['l'-'a'];
        int ocnt = cnt['o'-'a'];
        int ncnt = cnt['n'-'a'];
        return min({bcnt, acnt, lcnt/2, ocnt/2, ncnt});
    }
};