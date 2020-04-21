/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
   public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        auto x = binaryMatrix.dimensions();
        int n = x[0] - 1, m = x[1];
        int ans = 2147483647;
        for (int i = 0; i <= n; ++i) {
            int s = 0, e = m - 1;
            while (s <= e) {
                int mid = s + e >> 1;
                if (binaryMatrix.get(i, mid))
                    e = mid - 1;
                else
                    s = mid + 1;
            }
            if (s == 0 && binaryMatrix.get(i, 0) == 0) s = -1;
            if (s == m) s = -1;
            if (s != -1) {
                ans = min(s, ans);
            }
        }
        if (ans == 2147483647) ans = -1;
        return ans;
    }
};