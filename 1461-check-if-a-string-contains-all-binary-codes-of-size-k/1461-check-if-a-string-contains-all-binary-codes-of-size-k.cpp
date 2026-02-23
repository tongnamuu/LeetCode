class Solution {
public:
    bool hasAllCodes(string s, int k) {
       long long temp = 0;
       set<long long> v;
       int m = min(k, (int)s.length());
       for(int i=0;i<m;i++) {
            temp<<=1;
            temp += (s[i]-'0');
       }
       v.insert(temp);
       for(int i=m;i<s.length();i++) {
        temp<<=1;
        temp &= (1<<k) -1;
        temp += (s[i]-'0');
        v.insert(temp);
       }
       return v.size() == (1<<k);
    }
};