class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
        vector<int> used(n);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i==j || used[j]) continue;
                if(contain(words[i], words[j])) {
                    used[j] = 1;
                    ans.push_back(words[j]);
                }

            }
        }
        return ans;
    }
    bool contain(string& x, string& y) {
        for(int i=0;i<x.size();i++) {
            bool find = true;
            for(int j=0;j<y.size();j++) {
                if(i+j >= x.size() || x[i+j] != y[j]) {
                    find = false;
                    break;
                }
            }
            if(find) {
                //cout<<x<<' '<<y<<'\n';
                return true;
            }
        }
        return false;
    }
};