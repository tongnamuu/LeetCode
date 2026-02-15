class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int i=0;
        string ans;
        int n = min(a.size(), b.size());
        int carry = 0;
        for(;i<n;i++) {
            int a1 = (a[i] == '1');
            int b1 = (b[i] == '1');
            int r = a1 + b1 + carry;
            if (r == 3) {
                ans += '1';
                carry = 1;
            } else if (r==2) {
                ans += '0';
                carry = 1;
            } else if (r==1) {
                ans += '1';
                carry = 0;
            } else {
                ans += '0';
                carry = 0;
            }
        }
        while(i<a.size()) {
            int a1 = (a[i] == '1');
            int r = a1 + carry;
            if (r == 3) {
                ans += '1';
                carry = 1;
            } else if (r==2) {
                ans += '0';
                carry = 1;
            } else if (r==1) {
                ans += '1';
                carry = 0;
            } else {
                ans += '0';
                carry = 0;
            }
            i++;
        }
        while(i<b.size()) {
            int b1 = (b[i] == '1');
            int r = b1 + carry;
            if (r == 3) {
                ans += '1';
                carry = 1;
            } else if (r==2) {
                ans += '0';
                carry = 1;
            } else if (r==1) {
                ans += '1';
                carry = 0;
            } else {
                ans += '0';
                carry = 0;
            }
            i++;
        }
        if(carry) {
            ans += '1';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};