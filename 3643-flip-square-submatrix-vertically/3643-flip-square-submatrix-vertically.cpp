class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int s = x;
        int e = x+k-1;
        while(s<e) {
            for(int i=y;i<y+k;i++) {
                int temp = grid[s][i];
                grid[s][i] = grid[e][i];
                grid[e][i] = temp;
            }
            s++;
            e--;
        }
        
        return grid;
    }
};