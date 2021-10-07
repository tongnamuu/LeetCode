class Solution {
public:
    const int dx[4]={0,0,-1,1};
    const int dy[4]={-1,1,0,0};
    bool find(const string& word, int idx, int x, int y, vector<vector<char>>& map,  vector<vector<int>>& visit) {
        if(map[x][y]!=word[idx]) return false;
        if(idx==word.length()-1) return true;
        bool ret = false;
        for(int dir=0;dir<4;++dir) {
            int nx = x+dx[dir];
            int ny = y+dy[dir];
            if(nx>=0&&nx<map.size()&&ny>=0&&ny<map[0].size() && !visit[nx][ny]) {
                visit[nx][ny] = 1;
                ret |= find(word, idx+1,nx,ny,map, visit);
                if(ret) return true;
                visit[nx][ny] = 0;
            }
        }
        return ret;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>>visit(board.size(), vector<int>(board[0].size()));
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[i].size();++j){
                visit[i][j] = 1;
                if(find(word, 0, i, j, board, visit)) return true;
                visit[i][j] = 0;
            }
        }
        return false;
    }
};