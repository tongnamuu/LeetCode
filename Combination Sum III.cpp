class Solution {
   public:
    void go(int idx, int target, vector<int>& temp, vector<vector<int>>& ans, int start) {
        if (idx == temp.size() && target == 0) {
            ans.push_back(temp);
            return;
        }
        if (target < 0) return;
        if (idx == temp.size()) return;
        for (int i = start + 1; i <= 9; ++i) {
            temp[idx] = i;
            go(idx + 1, target - i, temp, ans, i);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp(k);
        for (int i = 1; i <= 9; ++i) {
            temp[0] = i;
            go(1, n - i, temp, ans, i);
        }
        return ans;
    }
};
