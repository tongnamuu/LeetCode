class Solution {
public:
    int d[501][501];
    int solve(vector<int>& a, int s, int e, int turn) {
        if(s>e) return 0;
        if(s==e) {
            return turn*a[s];
        }
        int& ret = d[s][e];
        if(ret!=-1) return ret;
        ret = max(turn*a[s] + solve(a, s+1, e, -turn), turn*a[e] + solve(a, s, e - 1, !turn));
        return ret;
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j) {
                d[i][j] = -1;
            }
        }
        int ans = solve(piles, 0, n - 1, 1);
        return ans > 0;
    }
};
