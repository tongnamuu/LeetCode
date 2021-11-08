class Solution {
public:
    int d[21];
    int numTrees(int n) {
        if(n <= 1) return 1;
        if(d[n]) return d[n];
        int& ans = d[n];
        for(int i = 1; i <= n; i++) 
            ans += numTrees(i-1) * numTrees(n-i);
        return ans;
    }
};