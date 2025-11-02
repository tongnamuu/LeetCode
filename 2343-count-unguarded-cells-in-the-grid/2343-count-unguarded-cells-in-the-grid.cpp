class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int solve(vector<vector<int>>& map, int m, int n, int x, int y, int dir) {
        if(x>=m || x < 0) return 0;
        if(y>=n || y < 0) return 0;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (map[x][y] & (1<<5)) {
            solve(map, m, n, nx, ny, dir);
            return 1;
        }
        if(map[x][y] & (1<<6)) {
            solve(map, m, n, nx, ny, dir);
            return -1;
        }
        int result = solve(map, m, n, nx, ny, dir);
        if(result == 1) {
            map[x][y] |= (1<<dir);
            return 1;
        } else {
            return -1;
        }


    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> map = vector<vector<int>>(m, vector<int>(n));
        for(vector<int>& x : guards) {
            map[x[0]][x[1]] |= (1<<5);
        }
        for(vector<int>& x : walls) {
            map[x[0]][x[1]] |= (1<<6);
        }
        for(int i=0;i<m;i++) {
            solve(map, m, n, i, 0, 1);
            solve(map, m, n, i, n-1, 3);
        }
        for(int i=0;i<n;i++) {
            solve(map, m, n, 0, i, 0);
            solve(map, m, n, m - 1, i, 2);
        }
        int ans = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(map[i][j]==0) ans++;
                //cout<<map[i][j]<<' ';
            }
            //cout<<'\n';
        }
        return ans;
    }
};