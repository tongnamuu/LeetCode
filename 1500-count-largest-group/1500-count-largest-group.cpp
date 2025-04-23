class Solution {
public:
    int cnt[100000];
    int countLargestGroup(int n) {
        int ans = 0;
        int val = 0;
        for(int i=1;i<=n;i++) {
            int d = digitSum(i);
            cnt[d]++;
            if(cnt[d]>ans) {
                ans = cnt[d];
                val = 1;
            } else if(cnt[d]==ans) {
                val++;
            }
        }
        return val;
    }

    int digitSum(int x) {
        int res = 0;
        while(x) {
            res += x % 10;
            x/=10;
        }
        return res;
    }
};