class Solution {
public:
    int f(int n) {
        int a = 0;
        int b = 1;
        while(n>0) {
            int x = n%10;
            n/=10;
            a += x;
            b *= x;
        }
        return a + b;
    }
    bool checkDivisibility(int n) {
        return (n%f(n)==0);
    }
};