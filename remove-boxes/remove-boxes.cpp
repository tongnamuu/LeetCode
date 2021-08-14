class Solution {
public:
    int d[101][101][101];
    int solve(vector<int>& a, int s, int e, int k) {
        if(s>e) return 0;
        if(s==e) return k*k;
        if(d[s][e][k]>0) return d[s][e][k];
        int temp = solve(a, s + 1, e, 1) + k*k;
        for(int i=s+1;i<=e;++i) {
            if(a[i]==a[s]) {
                temp = max(temp, solve(a, s + 1, i - 1, 1) + solve(a, i, e, k + 1));
            }
        }
        return d[s][e][k] = temp;
    }
    int removeBoxes(vector<int>& boxes) {
        return solve(boxes, 0, boxes.size()-1,1);
    }
};
