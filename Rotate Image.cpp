class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int s = 0, k = n - 1; k > 0; ++s, k -= 2) {
            int x = s, y = s;
            for (int i = 0; i < k; ++i) {
                int temp1 = matrix[s][s + i];
                matrix[s][s + i] = matrix[s + k - i][s];
                matrix[s + k - i][s] = matrix[s + k][s + k - i];
                matrix[s + k][s + k - i] = matrix[s + i][s + k];
                matrix[s + i][s + k] = temp1;
            }
        }
    }
};