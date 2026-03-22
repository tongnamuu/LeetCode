class Solution {
public:
    vector<vector<int>> rotate(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>> result = vector<vector<int>>(n, vector<int>(n));
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                int x = j;
                int y = n - i - 1;
                result[x][y] = a[i][j];
            }
        }
        return result;
    }
    bool ok(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(mat[i][j]!=target[i][j]) return false;
            }
        }
        return true;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(ok(mat, target)) return true;
        vector<vector<int>> temp = rotate(mat);
        if(ok(temp, target)) return true;
        temp = rotate(temp);
        if(ok(temp, target)) return true;
        temp = rotate(temp);
        if(ok(temp, target)) return true;
        return false;
    }
};