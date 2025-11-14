class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> a(n, vector<int>(n));
        for(vector<int>& q : queries) {
            int x1 = q[0];
            int y1 = q[1];
            int x2 = q[2];
            int y2 = q[3];
            for(int j=y1;j<=y2;j++) {
                a[x1][j] += 1;
                if (x2+1 < n) {
                    a[x2+1][j] += -1;
                }
            }
        }
        for(int j=0;j<n;j++) {
            for(int i=1;i<n;i++) {
                a[i][j] += a[i-1][j];
            }
        }
        return a;
    }
};