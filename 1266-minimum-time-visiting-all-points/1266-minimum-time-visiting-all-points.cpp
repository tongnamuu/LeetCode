class Solution {
public:
    int getDist(vector<int>& a, vector<int>& b) {
        int x0 = a[0];
        int y0 = a[1];
        int x1 = b[0];
        int y1 = b[1];
        return max(abs(x0-x1), abs(y0-y1));
    }
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for(int i=1;i<points.size();i++) {
            ans += getDist(points[i-1], points[i]);
        }
        return ans;
    }
};