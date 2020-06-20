class Solution {
   public:
    void go(int now, int current_color, const vector<vector<int>>& adj, vector<int>& color) {
        color[now] = current_color;
        for (int next : adj[now]) {
            if (!color[next]) {
                go(next, 3 - current_color, adj, color);
            }
        }
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> color(N + 1);
        vector<vector<int>> adj;
        adj.resize(N + 1);
        for (auto p : dislikes) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        for (int i = 1; i <= N; ++i) {
            if (!color[i]) {
                go(i, 1, adj, color);
            }
        }
        for (int i = 1; i <= N; ++i) {
            for (int next : adj[i]) {
                if (color[i] == color[next])
                    return false;
            }
        }
        return true;
    }
};