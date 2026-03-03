class Solution {
public:
    char solve(int n, int k) {
        if(n==1) return '0';
        int len = (1<<n);
        if (k<len/2) return solve(n-1, k);
        else if(k==len/2) return '1';
        else {
            char res = solve(n-1, len-k);
            return '1' - res + '0';
        }
    }
    char findKthBit(int n, int k) {
        return solve(n,k);
    }
};