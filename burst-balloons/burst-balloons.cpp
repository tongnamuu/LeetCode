class Solution {
public:
    int dp[505][505];
    int maxCoins(vector<int>& a) {
        int nums[a.size() + 2];
        int n = 1;
        for (int x : a) if (x > 0) nums[n++] = x;
        nums[0] = nums[n++] = 1;


       
        for (int k = 2; k < n; ++k) {
        for (int l = 0; l < n - k; ++l) {
            int right = l + k;
            for (int i = l + 1; i < right; ++i)
                dp[l][right] = max(dp[l][right],
                     nums[l] * nums[i] * nums[right] + dp[l][i] + dp[i][right]);
            }
        }
        return dp[0][n - 1];
    }
};