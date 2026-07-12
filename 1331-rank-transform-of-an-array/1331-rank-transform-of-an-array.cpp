class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n==0) return arr;
        vector<pair<int, int>> b(n);
        for(int i=0;i<n;i++) {
            b[i] = {arr[i], i};
        }
        sort(b.begin(), b.end());
        int idx = 1;
        vector<int>ans(n);
        ans[b[0].second] = idx;
        for(int i=1;i<n;i++) {
            if(b[i].first != b[i-1].first) idx++;
            ans[b[i].second] = idx;
        }
        return ans;
    }
};