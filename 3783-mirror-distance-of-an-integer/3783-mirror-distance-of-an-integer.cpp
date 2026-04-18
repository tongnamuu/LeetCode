class Solution {
public:
    int reverse(int x) {
        if(x==0) return x;
        int ans = 0;
        while(x) {
            ans *= 10;
            ans += x % 10;
            x /= 10;
        }
        return ans;
    }
    int mirrorDistance(int n) {
        return abs(n-reverse(n));
    }
};