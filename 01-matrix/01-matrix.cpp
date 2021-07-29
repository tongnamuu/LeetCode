class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m =mat[0].size();
        vector<vector<int>>d(n, vector<int>(m, -1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                if(!mat[i][j]) {
                    q.push({i, j});
                    d[i][j] = 0;
                }
            }
        }
        int nx,ny;
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            nx = x - 1;
            ny = y;
            if(nx>=0 && nx<n && ny>=0&&ny<m && d[nx][ny] == -1 && mat[nx][ny]==1) {
                q.push({nx,ny});
                d[nx][ny] = d[x][y] + 1;
            }
            nx = x + 1;
            if(nx>=0 && nx<n && ny>=0&&ny<m && d[nx][ny] == -1 && mat[nx][ny]==1) {
                q.push({nx,ny});
                d[nx][ny] = d[x][y] + 1;
            }
            nx = x;
            ny = y + 1;
            if(nx>=0 && nx<n && ny>=0&&ny<m && d[nx][ny] == -1 && mat[nx][ny]==1) {
                q.push({nx,ny});
                d[nx][ny] = d[x][y] + 1;
            }
            ny = y - 1;
            if(nx>=0 && nx<n && ny>=0&&ny<m && d[nx][ny] == -1 && mat[nx][ny]==1) {
                q.push({nx,ny});
                d[nx][ny] = d[x][y] + 1;
            }
        }
        return d;
    }
};
