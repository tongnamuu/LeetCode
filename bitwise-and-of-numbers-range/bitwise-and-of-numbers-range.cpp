class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(n==m) return n;
        while(m<n){
            n-=(n&-n);
        }
        return n;
    }
};
