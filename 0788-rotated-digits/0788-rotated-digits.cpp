class Solution {
public:
    int isGood(int x) {
        int v = 0;
        int isChanged = 0;
        while(x) {
            int t = x % 10;
            if(t==3||t==4||t==7) return 0;
            if(t==2||t==5||t==6||t==9) isChanged = 1;
            x/=10;
        }
        return isChanged;
    }
    int rotatedDigits(int n) {
        int ans = 0;
        for(int i=1;i<=n;i++) {
            ans += isGood(i);
        }
        return ans;
    }
};