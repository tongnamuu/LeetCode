class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        int x = 0;
        vector<int>ans(n);
        for(int i=0;i<n;i++) {
            if (seq[i]=='(') {
                x++;
                ans[i] = x % 2;
            } else {
                ans[i] = x % 2;
                x--;
            }
        }
        return ans;
    }
};