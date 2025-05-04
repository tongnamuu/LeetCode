class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        for(vector<int>& a : dominoes) {
            sort(a.begin(), a.end());
        }
        sort(dominoes.begin(), dominoes.end(), [&](const vector<int>& u, const vector<int>& v){
            if(u[0]==v[0]) {
                return u[1] < v[1];
            }
            return u[0] < v[0];
        });
        vector<int>& prev = dominoes[0];
        int ans = 0;
        int idx = 0;
        for(int i=1;i<dominoes.size();i++) {
            if(prev[0] == dominoes[i][0] && prev[1] == dominoes[i][1]) {
                continue;
            } else {
                int cnt = i-1 -idx + 1;
                ans += cnt*(cnt-1) / 2;
                idx = i;
                prev = dominoes[i];
            }
        }
        int cnt = dominoes.size()-1 -idx + 1;
        ans += cnt*(cnt-1) / 2;
        return ans;
    }
};