class Solution {
public:
    bool dist(string& u, string& v) {
        int n = u.length();
        int m = v.length();
        if(n!=m) return false;
        int cnt = 0;
        for(int i=0;i<n;i++) {
            if(u[i]!=v[i]) cnt++;
        }
        return cnt<=2;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        for(string& q : queries) {
            for(string& d:dictionary) {
                if(dist(q,d)) {
                    ans.push_back(q);
                    break;
                }
            }
        }
        return ans;
    }
};