class Solution {
public:
    int n, m;
    int visit[101][101];
    const int dx[4] = {0,0,-1,1};
    const int dy[4] = {-1,1,0,0};
    void solve(int x, int y, int& ans, vector<vector<int>>& a) {
        visit[x][y] = 1;
        for(int dir=0;dir<4;++dir){
            int nx = x+dx[dir];
            int ny = y+dy[dir];
            if(nx>=0&&nx<n&&ny>=0&&ny<m && a[nx][ny]==1) {
                if(!visit[nx][ny]) solve(nx,ny,ans,a);
            } else {
                ++ans;
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==1) {
                    int ans = 0;
                    solve(i,j,ans,grid);
                    return ans;
                }
            }
        }
        return 0;
    }
};