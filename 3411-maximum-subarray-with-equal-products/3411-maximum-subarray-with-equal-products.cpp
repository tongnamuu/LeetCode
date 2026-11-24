class Solution {
public:
    long long myGcd(long long x, long long y) {
        if(y==0) return x;
        long long r = x % y;
        return myGcd(y, r);
    }
    long long myLcm(long long x, long long y) {
        long long gcd = myGcd(x, y);
        return x*y / gcd;
    }
    int maxLength(vector<int>& a) {
        int n = a.size();
        int ans = 1;
        for(int i=0;i<n;i++) {
            long long prod = a[i];
            long long gcd = a[i];
            long long lcm = a[i];
            for(int j=i+1;j<n;j++) {
                prod = prod * a[j];
                lcm = myLcm(lcm, a[j]);
                gcd = myGcd(gcd, a[j]);
                if(prod > lcm * gcd) break;
                if(prod==lcm*gcd) {
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};