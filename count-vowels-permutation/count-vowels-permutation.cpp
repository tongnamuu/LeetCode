class Solution {
public:
    long long d[20020][5];
    int MOD = 1000000007;
    int countVowelPermutation(int n) {
        for(int i=0;i<5;++i) {
            d[1][i] = 1;
        }
        for(int i=2;i<=n;++i) {
            d[i][0] = d[i-1][1]; //a
            d[i][1] = d[i-1][0] + d[i-1][2];//e
            d[i][1] %= MOD;
            d[i][2] = d[i-1][0] + d[i-1][1] + d[i-1][3] + d[i-1][4];//i
            d[i][2] %= MOD;
            d[i][3] = d[i-1][2] + d[i-1][4];//o
            d[i][3] %= MOD;
            d[i][4] = d[i-1][0];//u
        }
        int ans = d[n][0];
        for(int i=1;i<5;++i){
            ans += d[n][i];
            ans %= MOD;
        }
        return ans;
    }
};
