class Solution {
public:
    int d[101];
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        d[0] = 1;
        int n = s.length();
        for(int i=1;i<n;++i){
            if(s[i]=='0') {
                if(s[i-1]=='0') {
                    return 0;
                }
                else if(s[i-1]=='1' || s[i-1]=='2') {
                    d[i] = (i>= 2 ? d[i-2] : 1);
                } else {
                    return 0;
                }
            }
            else if(s[i]>='1' && s[i] <='6') {
                if(s[i-1]=='1' || s[i-1]=='2') d[i] = d[i-1] + (i>=2?d[i-2]:1);
                else d[i] = d[i-1];
            }
            else if(s[i]>='7' && s[i]<='9') {
                if(s[i-1]=='1') d[i] = d[i-1] + (i>=2?d[i-2]:1);
                else d[i] = d[i-1];
            }
        }
        return d[n - 1];
    }
};
