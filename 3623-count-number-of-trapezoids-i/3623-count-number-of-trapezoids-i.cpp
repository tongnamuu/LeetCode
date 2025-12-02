class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        long long mod = 1000000007L;
        long long ans = 0;
        map<int, int> count;
        for(vector<int>& p : points) {
            count[p[1]]++;
        }
        long long cur = 0L;
        for(auto i = count.begin();i!=count.end();i++) {
            long long cnt = i -> second;
            if (cnt > 1) {
                long long x = (cnt*(cnt-1))/2;
                ans += cur * x;
                ans %= mod;
                cur += x;
                cur %= mod;
                
            }
        }
        return ans;
    }
};