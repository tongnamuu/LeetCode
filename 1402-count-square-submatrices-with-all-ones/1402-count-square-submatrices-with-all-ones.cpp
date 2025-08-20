class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(!n) return 0;
        int m = matrix[0].size();
        vector<vector<int>>d(n,vector<int>(m));
        int ans = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(matrix[i][j]==1){
                    int x = i?d[i-1][j]:0;
                    int y = j?d[i][j-1]:0;
                    int z = (i&&j)?d[i-1][j-1]:0;
                    d[i][j]=min({x,y,z})+1;
                    ans+=d[i][j];
                }
            }
        }
        return ans;
    }
};