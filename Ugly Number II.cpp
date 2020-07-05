class Solution {
   public:
    int nthUglyNumber(int n) {
        vector<int> ans;
        for (long long i = 1; i < 2147483647; i *= 2) {
            for (long long j = i; j < 2147483647; j *= 3) {
                for (long long k = j; k < 2147483647; k *= 5) {
                    ans.push_back(k);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans[n - 1];
    }
};