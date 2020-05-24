class Solution {
   public:
    vector<int> intersect(const vector<int>& a, const vector<int>& b) {
        int s = max(a[0], b[0]);
        int e = min(a[1], b[1]);
        vector<int> ans;
        if (s > e) return ans;
        ans.push_back(s);
        ans.push_back(e);
        return ans;
    }
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        int m = B.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                auto temp = intersect(A[i], B[j]);
                if (!temp.empty()) {
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};