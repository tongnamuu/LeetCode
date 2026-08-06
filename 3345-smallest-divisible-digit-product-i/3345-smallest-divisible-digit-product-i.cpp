class Solution {
public:
    int digitProduct(int n) {
        int result = 1;
        while(n) {
            result *= n % 10;
            n /= 10;
        }
        return result;
    }
    int smallestNumber(int n, int t) {
        for(int i=n;;i++) {
            if(digitProduct(i) % t == 0) {
                return i;
            }
        }
        return 0;
    }
};