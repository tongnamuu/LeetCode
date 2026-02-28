class Solution {
public:
    string tobin(int x) {
        if(x==0) return "0";
        string temp;
        while(x) {
            if(x&1) {
                x+='1';
            } else {
                x+= '0';
            }
            x>>=1;
        }
        return temp;
    }
    int concatenatedBinary(int n) {
        long long val = 0;
        for(int i=1;i<=n;i++) {
            int x = i;
            bool find=false;
            for(int j=31;j>=0;j--) {
                if(x&(1<<j)) {
                    find = true;
                }
                if (find) {
                    if(x&(1<<j)) {
                        val <<= 1;
                        val += 1;
                    } else {
                        val <<= 1;
                    }
                    val %= 1000000007L;
                }
            }
        }
        return val;
    }
};