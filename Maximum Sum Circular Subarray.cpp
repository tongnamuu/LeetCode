class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& a) {
        int n = a.size();
        vector<int> d(n);
        d[0] = a[0];
        int ans = a[0];
        for (int i = 1; i < n; ++i) {
            d[i] = max(d[i - 1] + a[i], a[i]);
            ans = max(d[i], ans);
        }
        vector<int> rsum(n);
        vector<int> rmax(n);
        rsum[n - 1] = rmax[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rsum[i] = rsum[i + 1] + a[i];
            rmax[i] = max(rsum[i], rmax[i + 1]);
        }
        int sum = 0;
        for (int i = 0; i < n - 2; ++i) {
            sum += a[i];
            ans = max(ans, sum + rmax[i + 1]);
        }
        return ans;
    }
};