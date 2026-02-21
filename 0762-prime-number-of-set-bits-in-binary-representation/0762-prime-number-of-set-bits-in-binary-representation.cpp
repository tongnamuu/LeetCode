class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i=left;i<=right;i++) {
            int bits = countBits(i);
            if(isPrime(bits)) {
                ans++;
            }
        }
        return ans;
    }
    int countBits(int x) {
        if(x==0) return 0;
        int ans = 0;
        while(x) {
            ans += (x&1);
            x >>= 1;
        }
        return ans;
    }
    int isPrime(int x) {
        if(x<=1) return false;
        if(x==2||x==3||x==5||x==7||x==11||x==13) return true;
        for(int i=2;i*i<=x;i++) {
            if((x%i)==0) return false;
        } 
        return true;
    }
};