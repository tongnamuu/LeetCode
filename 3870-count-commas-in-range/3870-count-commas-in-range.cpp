class Solution {
public:
    int countCommas(int n) {
        int ans = 0;
        for(int i=1000;i<=n;i++) {
            int temp = i;
            while(temp>=1000) {
                temp /= 1000;
                ans++;
            }
        }
        return ans;
    }
};