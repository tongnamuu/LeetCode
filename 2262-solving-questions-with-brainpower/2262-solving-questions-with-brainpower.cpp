class Solution {
public:
    long long d[1000000][2];
    long long solve(int idx, int select, vector<vector<int>>& q) {
        if(idx>= q.size()) {
            return 0L;
        }
        if(d[idx][select]!= -1) return d[idx][select];
        if(select == 0) {
            return d[idx][0] = max(solve(idx+1, 0, q), solve(idx+1, 1, q));
        } else {
            int next = idx + q[idx][1] + 1;
            return d[idx][1] = max(solve(next, 0, q), solve(next,1,q)) + (long long) q[idx][0];
        }
    }
    long long mostPoints(vector<vector<int>>& q) {
        for(int i=0;i<q.size();i++) d[i][0] = -1, d[i][1] = -1;
        solve(0, 0, q);
        solve(0,1,q);
        long long ans = 0;
        for(int i=0;i<q.size();i++) {
            ans = max({ans, d[i][0], d[i][1]});
        }
        return ans;
    }
};