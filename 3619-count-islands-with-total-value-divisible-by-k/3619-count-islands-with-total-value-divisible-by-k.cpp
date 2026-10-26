class Solution {
public:
    const int dx[4] = {0,0,-1,1};
    const int dy[4] = {-1,1,0,0};
    long long bfs(vector<vector<int>>& a, vector<vector<int>>& visit, int sx, int sy) {
        queue<pair<int,int>>q;
        int n = a.size();
        int m = a[0].size();
        q.push({sx,sy});
        visit[sx][sy]=1;
        long long ans = 0;
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            ans += a[x][y];
            for(int dir=0;dir<4;dir++) {
                int nx= x+dx[dir];
                int ny =y+dy[dir];
                if(nx>=0&&nx<n&&ny>=0&&ny<m) {
                    if(a[nx][ny]>0 && visit[nx][ny]==0) {
                        q.push({nx,ny});
                        visit[nx][ny]=1;
                    }
                }
            }
        }
        return ans;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visit(n, vector<int>(m));
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==0) continue;
                if(visit[i][j]!=0) continue;
                if(bfs(grid, visit, i, j)%k==0) ans++;
            }
        }
        return ans;
    }
};