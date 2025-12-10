class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int x = complexity[0];
        int n = complexity.size();
        for(int i=1;i<n;i++) {
            if(complexity[i]<=x) {
                return 0;
            }
        }
        long long mod = 1000000007L;
        long long ans = 1L;
        for(long long i=1L;i<=n-1;i++) {
            ans *= i;
            ans %= mod;
        }
        return ans;
    }
};