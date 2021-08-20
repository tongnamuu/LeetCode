class Solution {
public:
    int num[11];
    void init() {for(int i=0;i<10;++i) num[i] = 0;}
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;++i) {
            init();
            for(int j=0;j<9;++j){
                if(board[i][j]>='0' && board[i][j] <='9') {
                    num[board[i][j]-'0']++;
                    if(num[board[i][j]-'0'] > 1) return false;
                }
            }
        }
        for(int j=0;j<9;++j) {
            init();
            for(int i=0;i<9;++i) {
                if(board[i][j]>='0' && board[i][j] <='9') {
                    num[board[i][j]-'0']++;
                    if(num[board[i][j]-'0']>1) return false;
                }
            }
        }
        for(int k=0;k<9;++k){
            init();
            int x = k / 3;
            int y = k % 3;
            x *= 3;
            y *= 3;
            for(int i=0;i<3;++i){
                for(int j=0;j<3;++j){
                    if(board[x+i][y+j]>='0' && board[x+i][y+j] <='9') {
                        num[board[x+i][y+j]-'0']++;
                        if(num[board[x+i][y+j]-'0']>1) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
