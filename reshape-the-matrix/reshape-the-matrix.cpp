class Solution {
public:
    int get_num(vector<vector<int>>& mat, int n, int m, int idx) {
        int r = idx / m;
        int c= idx % m;
        return mat[r][c];
    }
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();
        if(n*m!=r*c) return mat;
        int index = 0;
        vector<vector<int>>ans = vector<vector<int>>(r, vector<int>(c, 0));
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                ans[i][j] = get_num(mat, n, m, index++);
            }
        }
        return ans;
    }
};
