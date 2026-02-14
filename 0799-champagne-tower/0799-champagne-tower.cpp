class Solution {
public:
    double a[105][105];
    double champagneTower(int poured, int query_row, int query_glass) {
        a[0][0] = poured;
        for(int x=0;x<query_row;x++) {
            for(int y=0;y<=x;y++) {
                double q = (a[x][y] - 1.0) / 2.0;
                if (q > 0) {
                    a[x+1][y] += q;
                    a[x+1][y+1] += q;
                }
            }
        }
        return min(1.0, a[query_row][query_glass]);
    }
};