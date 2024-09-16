class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int>a(2*n);
        for(int i=0;i<n;i++) {
            int x1 = timePoints[i][0]-'0';
            int x2 = timePoints[i][1]-'0';
            int x3 = timePoints[i][3]-'0';
            int x4 = timePoints[i][4]-'0';
            a[i] = 60 * (x1*10 + x2) + (x3*10 + x4);
            a[i+n] = a[i] + 24 * 60;
        }
        sort(a.begin(), a.end());
        int ans = 2147483647;
        for(int i=1;i<2*n;i++) {
            if(a[i]-a[i-1] < ans) {
                ans = a[i] - a[i-1];
            }
        }
        return ans;
    }
};