class Solution {
public:
    long long d[201][201];
    long long cnt[201][201];
    const long long MOD = 1000000007L;
    int countPaths(int n, vector<vector<int>>& roads) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                d[i][j] = 10000000000000L;
                if(i==j) {
                    d[i][j] = 0L;
                    cnt[i][j] = 1L;
                }
            }
        }
        for(auto& r : roads) {
            int u = r[0];
            int v = r[1];
            int c = r[2];
            d[u][v] = c;
            d[v][u] = c;
            cnt[u][v] = 1L;
            cnt[v][u] = 1L;
        }
        for(int k=0;k<n;k++) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if(i==k || k == j) continue;
                    if(d[i][j] > d[i][k] + d[k][j]) {
                        d[i][j] = d[i][k] + d[k][j];
                        cnt[i][j] = cnt[i][k] * cnt[k][j];
                        cnt[i][j] %= MOD;
                    } else if (d[i][j] == d[i][k] + d[k][j]) {
                        cnt[i][j] = (cnt[i][j] + cnt[i][k] * cnt[k][j]);
                        cnt[i][j] %= MOD;
                    }
                }
            }
        }
        return cnt[0][n-1];
    }
};