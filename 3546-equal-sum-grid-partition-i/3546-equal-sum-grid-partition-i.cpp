class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        long long total = 0;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) total += a[i][j];
        vector<long long>h(n);
        vector<long long>v(m);
        for(int i=0;i<n;i++) {
            long long sum = 0;
            for(int j=0;j<m;j++) {
                sum += a[i][j];
            }
            h[i] = sum;
            if (i>0) {
                h[i] += h[i-1];
            }
            if(h[i]*2== total) {
                return true;
            }
        }

        for(int i=0;i<m;i++) {
            long long sum = 0;
            for(int j=0;j<n;j++) {
                sum += a[j][i];
            }
            v[i] = sum;
            if (i>0) {
                v[i] += v[i-1];
            }
            if(v[i]*2 == total) {
                return true;
            }
        }
        return false;
    }
};