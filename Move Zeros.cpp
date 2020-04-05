class Solution {
   public:
    void solve(int s, int e, vector<int>& a) {
        if (s == e) return;
        int m = s + e >> 1;
        solve(s, m, a);
        solve(m + 1, e, a);
        int i = s, j = m + 1;
        int index = s;
        while (i <= m && a[i]) {
            a[index] = a[i];
            ++index;
            ++i;
        }
        while (j <= e && a[j]) {
            a[index] = a[j];
            ++index;
            ++j;
        }
        for (; index <= e; ++index) {
            a[index] = 0;
        }
    }
    void moveZeroes(vector<int>& nums) {
        solve(0, nums.size() - 1, nums);
    }
};