class Solution {
public:
    int p[51];
    int sz[51];
    int findParent(int x) {
        if(x==p[x]) return x;
        return p[x] = findParent(p[x]);
    }
    void merge(int x, int y) {
        x = findParent(x);
        y = findParent(y);
        if(x==y) return;
        p[x] = y;
        sz[y] += sz[x];
    }
    vector<int>adj[51];
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        for(int i=0;i<n;i++) {
            p[i] = i;
            sz[i] = 1;
        }
        for(vector<int>& e : edges) {
            int u = e[0];
            int v = e[1];
            merge(u, v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        set<int> parents;
        set<int> bads;
        for(int i=0;i<n;i++) {
            int cur = i;
            int p = findParent(cur);
            int target = sz[p] - 1;
            parents.insert(p);
            if (adj[cur].size()!=target) {
                bads.insert(p);
            }
        }
        int ans = parents.size() - bads.size();
        return ans;
    }
};