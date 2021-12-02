class Solution {
public:
    struct D {
        int now, cost, cnt;
        bool operator<(const D& a) const {
            return cost > a.cost;
        }
    };
    vector<pair<int, int>>adj[101];
    long long d[101][103];
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        for(auto& v:flights) {
            int from = v[0];
            int to = v[1];
            int c = v[2];
            adj[from].emplace_back(to, c);
            //adj[to].emplace_back(from, c);
        }
        for(int i=0;i<100;++i){
            for(int j=0;j<101;++j){
                d[i][j] = 1000000000;
            }
        }
        priority_queue<D>q;
        q.push({src, 0, 0});
        d[src][0] = 0;
        while(!q.empty()) {
            int now = q.top().now;
            int c = q.top().cost;
            int cnt = q.top().cnt;
            q.pop();
            if(d[now][cnt] < c) continue;
            for(auto p : adj[now]) {
                int next = p.first;
                int nc = p.second + c;
                if(d[next][cnt + 1] > nc) {
                    d[next][cnt+1] = nc;
                    q.push({next, nc, cnt+1});
                }
            }
        }
        int ans = 1000000000;
        for(int i=0;i<=k+1;++i) {
            if(d[dst][i] < ans) {
                ans = d[dst][i];
            }
        }
        if(ans==1000000000) ans = -1;
        return ans;
        
    }
};