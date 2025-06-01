class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        for(int i=0;i<=min(limit, n);i++) {
            int mx = min(i+limit, n);
            int mn = max(n - limit, i);
            ans += max((mx-mn+1), 0);
        }
        return ans;
    }
};