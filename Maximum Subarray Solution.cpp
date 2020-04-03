class Solution {
   public:
    int maxSubArray(vector<int>& a) {
        int n = a.size();
        int ans = a[0];
        vector<int> d = a;
        for (int i = 0; i < n; ++i) {
            if (i == 0) continue;
            d[i] = max(d[i - 1] + a[i], d[i]);
            ans = max(d[i], ans);
        }
        return ans;
    }
};