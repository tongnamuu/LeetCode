class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k==1) {
            string ans = s, x;
            int n = s.length();
            for(int i=1;i<n;++i) {
                x = s.substr(i,n-i)+s.substr(0,i);
                if(x<ans) ans = x;
            }
            return ans;
        }
        sort(s.begin(), s.end());
        return s;
    }
};