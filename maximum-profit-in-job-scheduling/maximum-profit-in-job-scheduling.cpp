class Solution {
public:
    struct D {
        int s, e, p;
        bool operator<(const D& a) const {
            if(s==a.s) {
                if(e==a.e) {
                    return p > a.p;
                }
                return e < a.e;
            }
            return s < a.s;
        }
    };
    int get_next_idx(int idx, vector<D>& a, int target) {
        int s = idx;
        int e = a.size() - 1;
        int ans = a.size();
        while(s<=e) {
            int m = s + e >> 1;
            if(a[m].s < target) {
                s = m + 1;
            } else {
                ans = m;
                e = m - 1;
            }
        }        
        return ans;
    }
    int solve(int idx, vector<D>& a, vector<int>& d) {
        if(idx>=a.size()) return 0;
        if(d[idx]!=-1) return d[idx];        
        int nextIdx = get_next_idx(idx, a, a[idx].e);
        int x = solve(nextIdx, a, d) + a[idx].p;
        int y = solve(idx+1, a, d);
        d[idx] = max(x, y);
        return d[idx];
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<D> a(n);
        vector<int>d(n);
        for(int i=0;i<n;++i){
            a[i].s = startTime[i];
            a[i].e = endTime[i];
            a[i].p = profit[i];
            d[i] = -1;
        }
        sort(a.begin(), a.end());
        return solve(0, a, d);
    }
};