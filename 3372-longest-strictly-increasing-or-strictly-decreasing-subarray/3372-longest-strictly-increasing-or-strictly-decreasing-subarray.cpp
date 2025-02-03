class Solution {
public:
    int longestMonotonicSubarray(vector<int>& a) {
        int n = a.size();
        vector<int>d(n);
        d[n-1] = 1;
        for(int i=n-2;i>=0;i--) {
            if (a[i+1] > a[i]) {
                d[i] = d[i+1] + 1;
            } else {
                d[i] = 1;
            }
        }
        int ans = *max_element(d.begin(), d.end());
        d[n-1] = 1;
        for(int i=n-2;i>=0;i--) {
            if (a[i+1] < a[i]) {
                d[i] = d[i+1] + 1;
            } else {
                d[i] = 1;
            }
        }
        int ans2 = *max_element(d.begin(), d.end());
        return max(ans, ans2);
    }
};