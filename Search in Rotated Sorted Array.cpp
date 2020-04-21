class Solution {
   public:
    int find(const vector<int>& a, int s, int e) {
        while (s < e) {
            int m = s + e >> 1;
            if (a[m] > a[e]) {
                if (a[m] > a[m + 1]) return m;
                s = m + 1;
            } else if (a[m] < a[e]) {
                if (a[m - 1] > a[m]) return m - 1;
                e = m - 1;
            } else
                return m;
        }
        return s;
    }
    int findv(vector<int>& a, int s, int e, int v) {
        while (s < e) {
            int m = s + e >> 1;
            if (a[m] < v)
                s = m + 1;
            else if (a[m] > v)
                e = m - 1;
            else
                return m;
        }
        return a[s] == v ? s : -1;
    }
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int s = 0, e = nums.size() - 1, m = s + e >> 1;
        if (nums[0] <= nums[m] && nums[m] <= nums[e]) {
            return findv(nums, 0, e, target);
        }
        int index = find(nums, 0, e);
        int ans = findv(nums, s, index, target);
        if (ans == -1) ans = findv(nums, index + 1, e, target);
        return ans;
    }
};