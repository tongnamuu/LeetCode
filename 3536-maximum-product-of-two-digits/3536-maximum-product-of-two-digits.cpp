class Solution {
public:
    int maxProduct(int n) {
        int v1 = 0;
        int v2 = 0;
        while(n) {
            int x = n%10;
            if(x>v1) {
                v2 = v1;
                v1 = x;
            } else if(x==v1) {
                v2 = v1;
                v1 = x;
            } else {
                if(x>v2) {
                    v2 = x;
                }
            }
            n /= 10;
        }
        return v1*v2;
    }
};