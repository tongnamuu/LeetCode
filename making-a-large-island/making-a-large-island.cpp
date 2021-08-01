class Solution {
public:
    const int dx[4] = {0,0,-1,1};
    const int dy[4] = {-1,1,0,0};
    int dfs(int x, int y, vector<vector<int>>& visit, vector<vector<int>>& grid, int cnt) {
        visit[x][y] = cnt;
        int res = 1;
        for(int dir=0;dir<4;++dir){
            int nx=x+dx[dir];
            int ny = y +dy[dir];
            if(nx>=visit.size() || nx < 0 || ny >= visit.size() || ny < 0) continue;
            if(!visit[nx][ny] && grid[nx][ny]) {
                res += dfs(nx, ny, visit, grid, cnt);
            }
        }
        return res;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>visit(n, vector<int>(n));
        map<int,int>m;
        map<int,int>f;
        int cnt = 1;
        int ans = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(!visit[i][j] && grid[i][j]) {
                    int res = dfs(i,j, visit, grid, cnt);
                    ans = max(ans, res);
                    m[cnt]=res;
                    cnt++;
                }
            }
        }
        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j){
                if(!grid[i][j]) {
                    int temp = 1;
                    f.clear();
                    for(int dir=0;dir<4;++dir) {
                        int nx=i+dx[dir];
                        int ny=j+dy[dir];
                        if(nx>=visit.size() || nx < 0 || ny >= visit.size() || ny < 0) continue;
                        if(!visit[nx][ny]) continue;
                        if(f.find(visit[nx][ny])==f.end()) {
                            temp += m[visit[nx][ny]];
                            f[visit[nx][ny]] = 1;
                        }
                        
                    }
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};
