class Solution {
public:
    long long sumAndMultiply(int n) {
        string temp;
        long long sum = 0;
        while(n>0) {
            int r = n % 10;
            if(r>0) {
                temp += (r+'0');
                sum += r;
            }
            n /= 10;
        }
        reverse(temp.begin(), temp.end());
        long long x = 0;
        for(char c : temp) {
            x*=10;
            x+=(c-'0');
        }
        return x*sum;
    }
};