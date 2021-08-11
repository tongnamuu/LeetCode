class Solution {
public:
    bool solve(vector<int>& arr) {
        int n =arr.size();
        if(n&1) return false;
        sort(arr.begin(), arr.end());
        vector<int>check(n);
        int prev = 0;
        int cnt = 0;
        for(int i=0;i<n;++i) {
            if(check[i]) continue;
            if(i == prev) prev++;
            int idx = lower_bound(arr.begin() + prev, arr.end(), 2*arr[i]) - arr.begin();
            if(idx>=n || arr[idx] != 2*arr[i]) return false;
            prev = idx + 1;
            ++cnt;
            check[idx] = 1;
        }
        return cnt == n/2;
    }
    bool canReorderDoubled(vector<int>& arr) {
        vector<int>a, b;
        for(int i:arr) {
            if(i<0) b.push_back(-i);
            else a.push_back(i);
        }
        return solve(a) && solve(b);
    }
};
