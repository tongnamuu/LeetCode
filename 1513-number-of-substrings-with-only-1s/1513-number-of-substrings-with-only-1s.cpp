class Solution {
public:
    int numSub(string s) {
        int cnt = 0;
        long long ans = 0;
        for(char c : s) {
            if(c=='0') {
                ans += (long long)cnt*(cnt+1)/2;
                ans %= 1000000007L;
                cnt = 0;
            } else {
                cnt++;
            }
        }
        ans += cnt*(cnt+1)/2;
        ans %= 1000000007L;
        return ans;
    }
};