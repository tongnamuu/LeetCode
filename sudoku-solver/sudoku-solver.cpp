class Solution {
public:
    int row[9];
    int col[9];
    int rec[9];
    vector<pair<int, int>> pos;
    bool solve(int idx, vector<vector<char>>& a) {
        if(idx==pos.size()) {
            return true;
        }
        
        for(int i=1;i<=9;++i) {
            int r = pos[idx].first;
            int c = pos[idx].second;
            int m = (r/3)*3 + c/3;
            if(row[r] & (1<<i)) continue;
            if(col[c] & (1<<i)) continue;
            if(rec[m] & (1<<i)) continue;
            row[r] |= (1<<i);
            col[c] |= (1<<i);
            rec[m] |= (1<<i);
            a[r][c] = (char)(i+'0');
            if(solve(idx+1, a)) return true;
            row[r] ^= (1<<i);
            col[c] ^= (1<<i);
            rec[m] ^= (1<<i);
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j]=='.') pos.push_back({i,j});
                else {
                    int num = board[i][j]-'0';
                    row[i] |= (1<<num);
                }
            }
        }
        
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[j][i]!='.'){
                    int num = board[j][i]-'0';
                    col[i] |= (1<<num);
                }
            }
        }
        for(int k=0;k<9;++k){
            int x = k / 3;
            int y = k % 3;
            x *= 3;
            y *= 3;
            for(int i=0;i<3;++i){
                for(int j=0;j<3;++j){
                    if(board[i+x][j+y]!='.') {
                        int num = board[i+x][j+y]-'0';
                        rec[k]|= (1<<num);
                    }
                }
            }
        }
        solve(0, board);
    }
};
