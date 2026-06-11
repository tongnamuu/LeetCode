class Solution {
public:
    vector<int> adj[100001];
    int dfs(int now) {
        int temp = 0;
        for(int next:adj[now]) {
            temp = max(temp, dfs(next));
        }
        return temp + 1;
    }
    long long pow(int n) {
        long long val = 1L;
        long long p = 2L;
        long long MOD = 1000000007L;
        while(n) {
            if(n&1) {
                val *= p;
                val %=MOD;
            }
            p *= p;
            p%=MOD;
            n /= 2;
        }


        return val;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
        }
        int cnt = dfs(1) - 1;
        long long ans = pow(cnt - 1);
        return ans;
    }
};