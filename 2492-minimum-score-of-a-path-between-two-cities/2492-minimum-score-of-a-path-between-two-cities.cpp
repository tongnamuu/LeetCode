class Solution {
public:
    int p[100001];
    int r[100001];
    int find(int x) {
        if(x==p[x]) return x;
        int nx = find(p[x]);
        r[x] = min(r[x], r[nx]);
        r[nx] = r[x];
        p[x] = nx;
        return p[x];
    }
    int merge(int x, int y, int c) {
        x = find(x);
        y = find(y);
        if(x!=y) {
            p[x] = y;
        }
        r[x] = min(c, min(r[x], r[y]));
        r[y] = r[x];
        return 1;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        for(int i=1;i<=n;i++) {
            p[i] = i;
            r[i] = 1000000000;
        }
        for(auto& road : roads) {
            int x = road[0];
            int y = road[1];
            int c = road[2];
            merge(x,y,c);
        }
        for(int i=1;i<=n;i++) {
           find(i);
        }
        return r[n];
    }
};