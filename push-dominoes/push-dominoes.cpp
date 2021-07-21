class Solution {
public:
    int d[100001][2];
    const int INF = 1000000000;
    
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        string ans = string(n , '.');
        d[0][0] = dominoes[0] == 'R' ? 0 : INF;
        for(int i=1;i<n;++i) {
            if(dominoes[i]=='R') {
                d[i][0] = 0;
            }
            else if(dominoes[i]=='L') {
                d[i][0] = INF;
            }
            else {
                d[i][0] = min(d[i - 1][0] + 1, INF);
            }
         
        }
        d[n - 1][1] = dominoes[n - 1] == 'L' ? 0 : INF;
        for(int i= n - 2;i >=0;--i) {
            if(dominoes[i]=='L') {
                d[i][1] = 0;
            }
            else if(dominoes[i]=='R') {
                d[i][1] = INF;
            }
            else{
                d[i][1] = min(d[i + 1][1] + 1, INF);
            }
        }
        for(int i = 0; i< n; ++i) {
            int r = d[i][0];
            int l= d[i][1];
            if(l > r) ans[i] = 'R';
            else if(l < r) ans[i] = 'L';
        }
        return ans;
    }
};
