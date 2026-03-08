class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string x = string(n, '0');
        for(int i=0;i<(1<<n);i++) {
            if(!find(nums,x)) {
                return x;
            }
            add(x);
        }
        return x;
    }

    bool find(vector<string>& nums, string& x) {
        for(string& j : nums) {
            if(j == x) return true;
        }
        return false;
    }
    void add(string& x) {
        int n = x.length();
        if(x[n-1] == '0') {
            x[n-1] = '1';
            return;
        }
        x[n-1] = '0';
        int carry = 1;
        for(int i=n-2;i>=0;i--) {
            if(x[i]=='1') {
                if(carry==1) {
                    x[i] = '0';
                    carry = 1;
                } else {
                    carry = 0;
                }
            } else if(x[i]=='0') {
                if(carry==1) {
                    x[i] = '1';
                    carry = 0;
                } 
                carry = 0;
                break;
            }
        }
    }
};