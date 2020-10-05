class Solution {
   public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int n = intervals.size();
        int start = intervals[0][0];
        int end = intervals[0][1];
        int ans = n;
        for (int i = 1; i < n; ++i) {
            int s = intervals[i][0];
            int e = intervals[i][1];
            if (start <= s && e <= end) {
                --ans;
            } else {
                start = s;
                end = e;
            }
        }
        return ans;
    }
};
