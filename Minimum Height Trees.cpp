class Solution {
   public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        if (n == 1) {
            ans.push_back(0);
            return ans;
        }
        vector<int> degree(n);
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            degree[e[0]]++;
            degree[e[1]]++;
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) q.push(i);
        }
        int total = n;
        while (total > 2) {
            int k = q.size();
            total -= k;
            while (k--) {
                int now = q.front();
                q.pop();
                for (int next : adj[now]) {
                    degree[next] -= 1;
                    if (degree[next] == 1) {
                        q.push(next);
                    }
                }
            }
        }
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
