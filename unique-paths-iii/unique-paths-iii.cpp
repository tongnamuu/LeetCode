class Solution {
public:
    const int dx[4] = {0,0,-1,1};
    const int dy[4] = {-1,1,0,0};
    void go(int x, int y, const int ex, const int ey, const vector<vector<int>>& a, vector<vector<int>>& visit, int& ans, const int cnt, int d){
        if(x==ex && y == ey){
            if(cnt == d) ++ans;
            return;
        }
        for(int dir=0;dir<4;++dir){
            int nx=x+dx[dir];
            int ny=y+dy[dir];
            if(nx>=0 && nx < a.size() && ny>=0 && ny <a[0].size()){
                if(a[nx][ny]==0 && !visit[nx][ny]){
                    visit[nx][ny] = 1;
                    go(nx, ny, ex, ey, a, visit, ans, cnt, d + 1);
                    visit[nx][ny] = 0;
                }
            }
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visit(n, vector<int>(m));
        int sx = -1, sy = -1, ex = -1, ey = -1;
        int cnt = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==-1){
                    continue;
                }
                cnt++;
                if(grid[i][j]==1){
                    sx=i,sy=j;
                    grid[i][j]=0;
                }
                else if(grid[i][j]==2){
                    ex=i,ey=j;
                    grid[i][j]=0;
                }
            }
        }
        visit[sx][sy] = 1;
        int ans = 0;
        go(sx, sy, ex, ey, visit,grid, ans, cnt, 1);
        return ans;
    }
};
