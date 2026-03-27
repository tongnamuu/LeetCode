class Solution {
public:

    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>a(n, vector<int>(m));
        for(int i=0;i<n;i++) {          
            for(int j=0;j<m;j++) {
                if(i&1) {
                    int newIdx = (j-(k%m)+m) % m;
                    a[i][newIdx] = mat[i][j];
                } else {
                    int newIdx = (j + k) % m;
                    a[i][newIdx] = mat[i][j];
                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j]!=a[i][j]) return false;
            }
        }     
        return true;        
    }
};