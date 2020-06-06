class Solution {
   public:
    int d[101][101];
    int go(int index, int left, vector<vector<int>>& costs) {
        if (index == costs.size()) {
            if (left) return 10000000;
            return 0;
        }
        int& ret = d[index][left];
        if (ret != -1) return ret;
        ret = go(index + 1, left, costs) + costs[index][1];
        if (left) ret = min(ret, go(index + 1, left - 1, costs) + costs[index][0]);
        return ret;
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        memset(d, -1, sizeof(d));
        return go(0, n / 2, costs);
    }
};