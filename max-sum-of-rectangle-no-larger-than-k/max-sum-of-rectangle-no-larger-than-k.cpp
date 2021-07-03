class Solution {
public:
    int d[101][101]={0,};
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m =matrix[0].size();
        cout<<n <<' '<<m<<'\n';
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                d[i][j]=matrix[i-1][j-1];
                d[i][j] += d[i-1][j];
                d[i][j] += d[i][j-1];
                d[i][j] -= d[i-1][j-1];
                cout<<d[i][j]<<' ';
            }
            cout<<'\n';
        }
        int ans = -2147483647;
        for(int i = 1;i<=n;++i) {
            for(int j = i;j<=n;++j) {
                for(int e=1;e<=m;++e) {
                    for(int l=e;l<=m;++l) {
                       int temp = d[j][l] - d[j][e - 1] - d[i - 1][l] + d[i - 1][e - 1];
                      
                        if(temp==k) return k;
                        if(temp<k) ans=max(ans, temp);
                    }
                }
            }
        }
        return ans;
    }
};